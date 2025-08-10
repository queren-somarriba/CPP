/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:21 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 17:14:25 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "--- Initial Tests ---" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;

	std::cout << "\n--- Arithmetic Operators ---" << std::endl;
	Fixed x(10.00f);
	Fixed y(3.00f);
	Fixed z(0.0f);

	std::cout << "x: " << x << ", y: " << y << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;

	// std::cout << "\n--- Division by Zero ---" << std::endl;
	// std::cout << "x / 0 = " << (x / z) << std::endl;

	std::cout << "\n--- Comparison Operators ---" << std::endl;
	std::cout << "x == y? " << (x == y) << std::endl;
	std::cout << "x != y? " << (x != y) << std::endl;
	std::cout << "x > y? "  << (x > y) << std::endl;
	std::cout << "x < y? "  << (x < y) << std::endl;
	std::cout << "x >= y? " << (x >= y) << std::endl;
	std::cout << "x <= y? " << (x <= y) << std::endl;

	std::cout << "\n--- Min / Max ---" << std::endl;
	std::cout << "min(x, y): " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y): " << Fixed::max(x, y) << std::endl;

	std::cout << "\n--- Conversion ---" << std::endl;
	std::cout << "x.toInt(): " << x.toInt() << std::endl;
	std::cout << "y.toFloat(): " << y.toFloat() << std::endl;

	return 0;
}