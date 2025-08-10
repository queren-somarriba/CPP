/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:23:39 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:37:03 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

/* Default constructors */
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const& brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

/* Default destructor */
Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

/* Assignment operator */
Brain& Brain::operator=(Brain const& other)//test copy profonde d'un brain
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	return (*this);
}

/* Getter / Setter */
std::string	Brain::getIdea(int const i) const
{
	if (i >= 0 && i < 100)
		return(this->ideas[i]);
	return ("");
}

void		Brain::setIdea(int const i , std::string const& idea)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
}