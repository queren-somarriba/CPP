/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:42:10 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:02:36 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

/* Constructors */
DiamondTrap::DiamondTrap(std::string const& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name + "lol"), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap default constructor called to create " << this->_name << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other)
: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called to create " << this->_name << std::endl;

}

/* Destructor */
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor called to delete " << this->_name << std::endl;
}

/* Assignment operator */
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const & other)
{
	std::cout << "DiamondTrap assignment operator called on " << this->_name << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

/* Member function */
void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap " << _name << " says: My name is " << _name
	          << ", my ClapTrap name is " << ClapTrap::_name << std::endl;
}

