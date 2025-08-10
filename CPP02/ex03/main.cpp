/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:50:20 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 13:58:32 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const& a, Point const& b, Point const& c, Point const& p)
{
	std::cout << "Test point (" << p.getX() << ", " << p.getY() << "): ";
	if (bsp(a, b, c, p))
		std::cout << "Inside the triangle ✅" << std::endl;
	else
		std::cout << "Outside the triangle ❌" << std::endl;
}

int main()
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);

	std::cout << "Triangle ABC: A(0,0), B(5,0), C(2.5,5)\n" << std::endl;

	// Point inside
	Point p1(2.5f, 2.0f);
	test(a, b, c, p1);

	// Point outside
	Point p2(5.0f, 5.0f);
	test(a, b, c, p2);

	// Point on edge
	Point p3(2.5f, 0.0f);
	test(a, b, c, p3);

	// Point on vertex
	Point p4(0.0f, 0.0f);
	test(a, b, c, p4);

	return 0;
}