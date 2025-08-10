/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:23:18 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:23:19 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "WrongAnimal default constructor called on " << this->_type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called on " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(std::string const& type) : _type(type)
{
	std::cout << "WrongAnimal parametrized constructor called on " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& a) : _type(a._type)
{
	std::cout << "WrongAnimal copy constructor called on " << this->_type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "WrongAnimal assignment oprator called on " << this->_type << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
}