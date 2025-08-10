/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:08:53 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:08:55 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called on " << this->_type << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called on " << this->_type << std::endl;
}
Dog::Dog(Dog const& dog) : Animal(dog._type)
{
	std::cout << "Dog copy constructor called on " << this->_type << std::endl;
}

Dog& Dog::operator=(Dog const& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
	}
	std::cout << "Dog assignemt operator called on " << this->_type << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << this->_type << ": Woof!" << std::endl;
}