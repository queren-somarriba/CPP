/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:20:50 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:20:52 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called on " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called on " << this->_type << std::endl;
}
Cat::Cat(Cat const& cat) : Animal(cat._type)
{
	std::cout << "Cat copy constructor called on " << this->_type << std::endl;
}

Cat& Cat::operator=(Cat const& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
	}
	std::cout << "Cat assignemt operator called on " << this->_type << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << this->_type << ": Meow!" << std::endl;
}
