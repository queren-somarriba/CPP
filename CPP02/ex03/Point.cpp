/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:57:53 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 17:22:09 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Constructors */

Point::Point(void) : _x(0), _y(0)
{
}
Point::Point(float const x, float const y): _x(x), _y(y)
{
}
Point::Point(Point const & p) : _x(p._x), _y(p._y)
{
}

/* Destructor */

Point::~Point(void)
{
}

/* Assignment operator */
Point&		Point::operator=(Point const & p)
{
	(void)p;
	return (*this);
}

/* Getters*/

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}