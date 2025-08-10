/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:34:10 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:48:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_array[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._array[i])
			this->_array[i] = other._array[i]->clone();
		else
			this->_array[i] = 0;
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_array[i])
			delete this->_array[i];
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_array[i])
				delete this->_array[i];
			if (other._array[i])
				this->_array[i] = other._array[i]->clone();
			else
				this->_array[i] = 0;
		}
	}
	return (*this);
}


void	MateriaSource::learnMateria(AMateria* materia)
{
	int	i = 0;

	if (materia)
	{
		while (this->_array[i])
			i++;
		if (i < 4)
		{
			if (this->_array[i])
				delete this->_array[i];
			this->_array[i] = materia;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int	i = 0;

	while (this->_array[i] && this->_array[i]->getType().compare(type))
		i++;
	if (i < 4 && this->_array[i])
		return (this->_array[i]->clone());
	else
		return (0);
}