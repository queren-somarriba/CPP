/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:23:27 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:44:46 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

/* Default constructors */
Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor called on " << this->_type << std::endl;
}

Cat::Cat(Cat const& cat) : Animal(cat), _brain(new Brain(*cat._brain))
{
	std::cout << "Cat copy constructor called on " << this->_type << std::endl;
}

/* Default destructor */
Cat::~Cat()
{
	std::cout << "Cat default destructor called on " << this->_type << std::endl;
	delete this->_brain;
}

/* Assignment operator */
Cat& Cat::operator=(Cat const& other)
{
	std::cout << "Cat assignemt operator called on " << this->_type << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

/* Getter / Setter */
void	Cat::setIdea(int const i, std::string const& idea)
{
	this->_brain->setIdea(i, idea);
}

std::string	Cat::getIdea(int const i) const
{
	return (this->_brain->getIdea(i));
}

/* Member function */
void Cat::makeSound() const
{
	std::cout << this->_type << ": Meow!" << std::endl;
}
