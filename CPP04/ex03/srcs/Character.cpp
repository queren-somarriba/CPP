/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:48:40 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/19 16:22:32 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

/* Constructors */
Character::Character() : _name("")
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
Character::Character(Character const& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
}

/* Destructor */
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

 /* Overload Operation = */
Character&	Character::operator=(Character const& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = 0;
			}
			this->_inventory[i] = other._inventory[i]->clone();
		}
		}
	return (*this);
}

/* Member functions */
std::string const&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;

	if (m)
	{
		while (this->_inventory[i] && i < 4)
			i++;
		if (i < 4)
			this->_inventory[i] = m->clone();
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && this->_inventory[idx] && idx < 4)
		this->_inventory[idx]->use(target);
}