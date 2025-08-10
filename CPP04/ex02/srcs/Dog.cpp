/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:42:20 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:43:11 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

/* Default constructors */
Dog::Dog() : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called on " << this->_type << std::endl;
}

Dog::Dog(Dog const& dog) : AAnimal(dog._type), _brain(new Brain(*dog._brain))
{
	std::cout << "Dog copy constructor called on " << this->_type << std::endl;
}

/* Default destructor */
Dog::~Dog()
{
	std::cout << "Dog default destructor called on " << this->_type << std::endl;
	delete this->_brain;
}

/* Assignment operator */
Dog& Dog::operator=(Dog const& other)
{
	std::cout << "Dog assignemt operator called on " << this->_type << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

/* Getter / Setter */
std::string	Dog::getIdea(int const i) const
{
	return (this->_brain->getIdea(i));
}

void	Dog::setIdea(int const i , std::string const& idea)
{
	this->_brain->setIdea(i, idea);
}

/* Member function */
void Dog::makeSound() const
{
	std::cout << this->_type << ": Woof!" << std::endl;
}