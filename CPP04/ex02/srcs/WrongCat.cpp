/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:41:58 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:42:08 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called on " << this->_type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called on " << this->_type << std::endl;
}
WrongCat::WrongCat(WrongCat const& Wrongcat) : WrongAnimal(Wrongcat._type)
{
	std::cout << "WrongCat copy constructor called on " << this->_type << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		this->_type = other._type;
	}
	std::cout << "WrongCat assignemt operator called on " << this->_type << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << this->_type << ": Wrong Meow!" << std::endl;
}
