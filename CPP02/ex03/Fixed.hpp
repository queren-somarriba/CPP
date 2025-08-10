/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:25 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 17:14:22 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int			_value;
	static int const	_bits_nb;
public:
	/* Constructors */
				Fixed(void);
				Fixed(Fixed const &);
				Fixed(int const);
				Fixed(float const);
				
	/* Destructor */
				~Fixed(void);
				
	/* Assignment operator */
	Fixed & 		operator=(Fixed const &);
				
	/* Comparison operators */
	bool 			operator==(Fixed const &) const;
	bool			operator<(Fixed const &) const;
	bool			operator>(Fixed const &) const;
	bool			operator>=(Fixed const &) const;
	bool			operator<=(Fixed const &) const;
	bool			operator!=(Fixed const &) const;

	/* Arithmetic operators */
	Fixed			operator+(Fixed const &) const;
	Fixed			operator-(Fixed const &) const;
	Fixed			operator*(Fixed const &) const;
	Fixed			operator/(Fixed const &) const;

	/* Increment / Decrement operators */
	Fixed &			operator++();
	Fixed			operator++(int);
	Fixed &			operator--();
	Fixed			operator--(int);

	/* Getters / Setters */
	int			getRawBits(void) const;
	void			setRawBits(int const);

	/* Conversion functions */
	float			toFloat(void) const;
	int			toInt(void) const;

	/* Min / Max functions */
	static Fixed&		min(Fixed &f1, Fixed &f2);
	static Fixed const&	min(Fixed const& f1, Fixed const& f2);
	static Fixed&		max(Fixed &f1, Fixed &f2);
	static Fixed const&	max(Fixed const& f1, Fixed const& f2);

};

/* Stream insertion operator */
std::ostream&		operator<<(std::ostream&, Fixed const&);

#endif 