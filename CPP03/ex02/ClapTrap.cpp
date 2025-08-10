/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:35:34 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 18:28:10 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

/* Constructors */
ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10),
_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called to create " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other) : _name(other._name),
_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called to create " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string const& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called to create " << this->_name << std::endl;
}


/* Destructor */
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap default destructor called to delete " << this->_name << std::endl;
}

/* Assignment operator */
ClapTrap&	ClapTrap::operator=(ClapTrap const& ct)
{
	std::cout << "ClapTrap assignment operator called on " << this->_name << std::endl;
	if (this != &ct)
	{
		this->_name = ct._name;
		this->_attackDamage = ct._attackDamage;
		this->_energyPoints = ct._energyPoints;
		this->_hitPoints = ct._hitPoints;
	}
	return (*this);
}

/* Member functions */
void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (this->_hitPoints < amount)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " take " << amount;
		std::cout << " points of damage! ([" << this->_hitPoints << "] hit Points)" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't take more damages" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaire " << amount;
		std::cout << " points of energy! ([" << this->_hitPoints << "] hit Points)" << std::endl;
		this->_energyPoints--;
	}
}
