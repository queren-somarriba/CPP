/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:32:05 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 13:03:20 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

#define GREEN   "\033[32m"
#define RED	"\033[31m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

int main()
{
	Data	data = {42, 123.456f, 'X', "hello"};
	Data*	data_ptr = &data;

	std::cout << BOLD << CYAN << "1. Original Data* address: " << RESET << RED << data_ptr << std::endl;
	std::cout << BOLD << CYAN << "Elements pointed to by data_ptr:" << std::endl
		<< RESET << "int= " << RED	<< data_ptr->int_value << std::endl
		<< RESET << "float= " << RED	<< data_ptr->float_value << std::endl
		<< RESET << "char= " << RED	<< data_ptr->char_value << std::endl
		<< RESET << "string= " << RED	<< data_ptr->string_value << std::endl;

	uintptr_t serialized_value = Serializer::serialize(data_ptr);

	std::cout << BOLD << CYAN << "2. Serialized value (as uintptr_t): " << RESET << RED	<< "0x" << std::hex << serialized_value << std::dec << std::endl;

	Data* deserialized_ptr = Serializer::deserialize(serialized_value);

	std::cout << BOLD << CYAN << "3. Deserialized Data* address: " << RESET << RED	<< deserialized_ptr << std::endl;

	if (data_ptr == deserialized_ptr)
	{
		std::cout << BOLD << GREEN << "4.  OK: Pointer values are equal!" << std::endl;
		std::cout << CYAN << "Deserialized_ptr elements: " << std::endl
		<< RESET << "int= " << RED	<< deserialized_ptr->int_value << std::endl
		<< RESET << "float= " << RED	<< deserialized_ptr->float_value << std::endl
		<< RESET << "char= " << RED	<< deserialized_ptr->char_value << std::endl
		<< RESET << "string= " << RED	<< deserialized_ptr->string_value << std::endl;
	}
	else
		std::cout << RED << "4.  Pointer values are different!" << std::endl;
	return (0);
}