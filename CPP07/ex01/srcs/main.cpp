/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:54:04 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 18:46:56 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void rotone(char & a)
{
	if ((a >= 'a' && a < 'z') || (a >= 'A' && a < 'Z'))
		a += 1;
	if (a == 'z' || a == 'Z')
		a -= 25;
}

void rrotone(char& a)
{
	if ((a > 'a' && a <= 'z') || (a > 'A' && a <= 'Z'))
		a -= 1;
	if (a == 'a' || a == 'A')
		a += 25;
}

void	square(int& i)
{
	i *= i;
}

void	printInt(int const& i)
{
	std::cout << i << " ";
}

int main()
{
	char str[] = "Hello Worldz";
	std::cout << "***Test with char***" << std::endl << std::endl;
	std::cout << "original str= " << str << std::endl;
	iter<char>(str, sizeof(str), rotone);
	std::cout << "str after iter(rotone)= " << str << std::endl;
	iter<char>(str, sizeof(str), rrotone);
	std::cout << "str after iter(rrotone)= " << str << std::endl;
	std::cout << std::endl << std::endl << "***Test with int***" << std::endl << std::endl;
	int int_array[6] = {0, 1, 2, 3, 4, 5};
	std::cout << "original array= ";
	iter<int>(int_array, 6, printInt);
	std::cout << std::endl;
	iter<int>(int_array, 6, square);
	std::cout << "array after iter(square)= ";
	iter<int>(int_array, 6, printInt);
	std::cout << std::endl;
	return (0);
}

