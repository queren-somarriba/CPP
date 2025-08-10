/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:48:41 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:48:45 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
}

AMateria::AMateria(std::string const& type) : _type(type)
{
}
AMateria::AMateria(AMateria const& other) : _type(other._type)
{
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=(AMateria const& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}