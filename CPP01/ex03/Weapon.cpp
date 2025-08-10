/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:31:35 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 15:00:04 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string const& str): _type(str)
{
}

Weapon::~Weapon(void)
{
}

std::string const&	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string const& str)
{
	this->_type = str;
}