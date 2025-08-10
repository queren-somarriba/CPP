/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:57:45 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 15:40:40 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	triangle_area(Point const& a, Point const& b, Point const& c)
{
	Fixed aera = ((b.getX() - a.getX()) * (c.getY() - a.getY())
		- (c.getX() - a.getX()) * (b.getY() -a.getY())) / Fixed(2);
	if (aera < Fixed(0))
		aera = aera * Fixed(-1);
	return (aera);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abc = triangle_area(a, b, c);
	Fixed	abp = triangle_area(a, b, point);
	Fixed	acp = triangle_area(a, c, point);
	Fixed	bcp = triangle_area(b, c, point);

	Fixed sum = abp + acp + bcp;
	Fixed epsilon(0.01f);

	return (abp > Fixed(0) && acp > Fixed(0) && bcp > Fixed(0)
		&& (sum - abc < epsilon));
}