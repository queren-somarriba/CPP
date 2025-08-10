/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:44:19 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:44:22 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("")
{
	std::cout << "AAnimal default constructor called on " << this->_type << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal default destructor called on " << this->_type << std::endl;
}

AAnimal::AAnimal(std::string const& type) : _type(type)
{
	std::cout << "AAnimal parametrized constructor called on " << this->_type << std::endl;
}

AAnimal::AAnimal(AAnimal const& a) : _type(a._type)
{
	std::cout << "AAnimal copy constructor called on " << this->_type << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "AAnimal assignment oprator called on " << this->_type << std::endl;
	return (*this);
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}
