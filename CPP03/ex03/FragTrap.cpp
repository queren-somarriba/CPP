/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:49:33 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 18:54:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/* Constructors */
FragTrap::FragTrap(std::string const& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called to create " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called to create " << this->_name << std::endl;
}

/* Destructor */
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap default destructor called to delete " << this->_name << std::endl;
}

/* Assignment operator */
FragTrap&	FragTrap::operator=(FragTrap const& st)
{
	std::cout << "FragTrap assignment operator called on " << this->_name << std::endl;
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
void	FragTrap::attack(std::string const& target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "FragTrap " << this->_name << " can't attack!" << std::endl;
}
void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " requests a high five! ✋" << std::endl;
}

