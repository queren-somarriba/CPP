/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:57:56 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 17:21:12 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
 	public:
		/* Constructors */
				Point(void);
				Point(float const, float const);
				Point(Point const &);
		/* Destructor */
				~Point(void);
		/* Assignment operator */
		Point&		operator=(Point const &);
		/* Getters */
		Fixed		getX(void) const;
		Fixed		getY(void) const;
};

#endif 