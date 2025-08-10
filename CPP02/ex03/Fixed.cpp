/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:28:26 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 13:52:35 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

int const Fixed::_bits_nb = 8;

/* Constructors */

Fixed::Fixed(void): _value(0)
{
}
Fixed::Fixed(Fixed const & f) : _value(f._value)
{
}


Fixed::Fixed(int const integer)
{
	this->_value = integer << _bits_nb;
}

Fixed::Fixed(float const nb)
{
	this->_value = static_cast<int>(roundf(nb * (1 << _bits_nb)));
}

/* Destructor */

Fixed::~Fixed()
{
}

/* Assignment operator */

Fixed & Fixed::operator=(Fixed const &f)
{
	if (this != &f)
		this->_value = f._value;
	return (*this);
}

/* Conversion functions */

float	Fixed::toFloat(void) const
{
	
	return (static_cast<float>(this->_value) / (1 << _bits_nb));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _bits_nb);
}

/* Comparison operators */

bool	Fixed::operator==(Fixed const &f) const
{
	return (this->_value == f._value);
}

bool	Fixed::operator<(Fixed const &f) const
{
	return (this->_value < f._value);
}

bool	Fixed::operator>(Fixed const &f) const
{
	return (this->_value > f._value);
}

bool	Fixed::operator>=(Fixed const &f) const
{
	return (this->_value >= f._value);
}

bool	Fixed::operator<=(Fixed const &f) const
{
	return (this->_value <= f._value);
}

bool	Fixed::operator!=(Fixed const &f) const
{
	return (this->_value != f._value);
}

/* Arithmetic operators */

Fixed	Fixed::operator+(Fixed const &f) const
{
	Fixed	res;

	res.setRawBits(this->_value + f._value);
	return (res);
}

Fixed	Fixed::operator-(Fixed const &f) const
{
	Fixed	res;

	res.setRawBits(this->_value - f._value);
	return (res);
}

Fixed	Fixed::operator*(Fixed const &f) const
{
	Fixed	res;

	long long product = static_cast<long long>(this->_value) * f._value;
	product = product >> _bits_nb;
	res.setRawBits(static_cast<int>(product));
	return (res);
}

Fixed	Fixed::operator/(Fixed const &f) const
{
	Fixed	res;
	if (f._value == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return (Fixed());
	}
	long long numerator = (static_cast<long long>(this->_value) << _bits_nb);
	long long quotient = numerator / f._value;
	res.setRawBits(static_cast<int>(quotient));
	return (res);
}

/* Increment / Decrement operators */

Fixed &	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++(*this);
	return (tmp);
}

Fixed &	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--(*this);
	return (tmp);
}

/* Getters / Setters */

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/* Min / Max functions */

Fixed&		Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed const&	Fixed::min(Fixed const& f1, Fixed const& f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed&		Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

Fixed const&	Fixed::max(Fixed const& f1, Fixed const& f2)
{
	return (f1 > f2 ? f1 : f2);
}

/* Stream insertion operator */

std::ostream&	operator<<(std::ostream& ofs, Fixed const& f)
{
	ofs << f.toFloat();
	return (ofs);
}