/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:55:25 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 19:03:31 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Span.hpp"

#define GREEN   "\033[32m"
#define RED	"\033[31m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

int main()
{
	try
	{
		std::cout << BOLD << CYAN << "Subject test:" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << RESET << "shortestSpan= " << GREEN << sp.shortestSpan() << std::endl;
		std::cout << RESET << "longestSpan= " << GREEN << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << BOLD << CYAN << "Class test(instenciation/copy):" << std::endl;
		Span sp = Span(7);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		Span sp2 = Span();
		sp2 = sp;
		std::cout << RESET << "Assignment operator test - sp2 = sp:" << std::endl;
		std::cout << RESET << "sp2 shortestSpan=" << GREEN << sp2.shortestSpan() << std::endl;
		std::cout << RESET << "sp2 longestSpan= " << GREEN << sp2.longestSpan() << std::endl;
		std::cout << RESET << "sp2 modif : addNumber(666), addNumber(999):" << std::endl;
		sp2.addNumber(666);
		sp2.addNumber(999);
		std::cout << "sp=  " << sp << std::endl;
		std::cout << "sp2= " << sp2 << std::endl;
		Span sp3(sp);
		std::cout << RESET << "Copy constructor test - sp3(sp):" << std::endl;
		std::cout << RESET << "sp3 shortestSpan=" << GREEN << sp2.shortestSpan() << std::endl;
		std::cout << RESET << "sp3 longestSpan= " << GREEN << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << BOLD << CYAN << "Max span size test:" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(std::numeric_limits<int>::max());
		sp.addNumber(std::numeric_limits<int>::min());
		std::cout << RESET << "shortestSpan= " << GREEN << sp.shortestSpan() << std::endl;
		std::cout << RESET << "longestSpan= " << GREEN << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	
	try
	{
		std::cout << std::endl << BOLD << CYAN << "Exception Test - sould throw \"Can't access an out of range index\":" << std::endl;
		Span sp = Span(3);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << BOLD << CYAN << "Exception Test - sould throw \"Not enough element to compute a span!\":" << std::endl;
		Span sp = Span(1);
		sp.addNumber(7);
		std::cout << RESET << "shortestSpan= " << GREEN << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD << RED << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << BOLD << CYAN << "Test with 10.000 value + function to fill the span" << RESET << std::endl;
		Span sp = Span(10000);
		sp.fillRandomN(10000);
		sp.insert(sp.getIterator(0), sp.getIterator(9999));

		std::cout << "sp= " << sp << std::endl;
		std::cout << RESET << "shortestSpan= " << GREEN << sp.shortestSpan() << std::endl;
		std::cout << RESET << "longestSpan= " << GREEN << sp.longestSpan() << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << BOLD << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
