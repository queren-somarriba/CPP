/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:31:37 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 18:31:38 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* Constructors */
ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called to create " << this->_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called to create " << this->_name << std::endl;
}

/* Destructor */
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap default destructor called to delete " << this->_name << std::endl;
}

/* Assignment operator */
ScavTrap&	ScavTrap::operator=(ScavTrap const& st)
{
	std::cout << "ScavTrap assignment operator called on " << this->_name << std::endl;
	if (this != &st)
	{
		this->_name = st._name;
		this->_attackDamage = st._attackDamage;
		this->_energyPoints = st._energyPoints;
		this->_hitPoints = st._hitPoints;
	}
	return (*this);
}

/* Member functions */
void	ScavTrap::attack(std::string const& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't attack!" << std::endl;
}
void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
