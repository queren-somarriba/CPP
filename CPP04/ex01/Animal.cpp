/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:22:37 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:23:53 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal default constructor called on " << this->_type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called on " << this->_type << std::endl;
}

Animal::Animal(std::string const& type) : _type(type)
{
	std::cout << "Animal parametrized constructor called on " << this->_type << std::endl;
}

Animal::Animal(Animal const& a) : _type(a._type)
{
	std::cout << "Animal copy constructor called on " << this->_type << std::endl;
}

Animal& Animal::operator=(Animal const& other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "Animal assignment oprator called on " << this->_type << std::endl;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
}