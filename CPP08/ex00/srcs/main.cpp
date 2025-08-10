/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:54:57 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/25 19:06:15 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "easyfind.hpp"

#define GREEN   "\033[32m"
#define RED	"\033[31m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

int main()
{
	std::vector <int>vect (8);
	int* vptr = vect.data();	
	std::cout << BOLD << CYAN << "Test with vector<int> :" << std::endl;
	for (int i = 0; i < 8; ++i)
		vptr[i] = i;
	std::cout << RESET << "Initial vector:" << std::endl;
	for (unsigned int i = 0; i < vect.size(); ++i)
	std::cout << vect[i] <<std::endl;
	std::cout << "easyfind(9) :" << std::endl;
	std::vector<int>::const_iterator it = easyfind(vect, 9);
	if (it != vect.end())
		std::cout <<BOLD << GREEN << "Element found: " << RESET << *it << std::endl;
	else
		std::cout << BOLD << RED << "Element not found" << std::endl;
	vect.push_back(9);
	std::cout << RESET << "easyfind(9) after push_back(9) :" << std::endl;
	it = easyfind(vect, 9);
	if (it != vect.end())
		std::cout <<BOLD << GREEN << "Element found: " << RESET << *it << std::endl;
	else
		std::cout << BOLD << RED << "Element not found" << std::endl;
	
	std::list <int>lst;
	std::cout << std::endl << BOLD << CYAN << "Test with list<int> :" << std::endl;
	std::cout << RESET << "easyfind(0) before list init: " << std::endl;
	std::list<int>::const_iterator it2 = easyfind(lst, 0);
	if (it2 != lst.end())
		std::cout <<BOLD << GREEN << "Element found: " << RESET << *it2 << std::endl;
	else
		std::cout << BOLD << RED << "Element not found" << std::endl;
	for (int i = 0; i < 8; ++i)
		lst.push_front(i * i);
	std::cout << RESET << "Initial list:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it <<std::endl;
	std::cout << "easyfind(25) :" << std::endl;
	it2 = easyfind(lst, 25);
	if (it2 != lst.end())
		std::cout <<BOLD << GREEN << "Element found: " << RESET << *it2 << std::endl;
	else
		std::cout << BOLD << RED << "Element not found" << std::endl;
	std::cout << RESET << "easyfind(25) after remove(25):" <<std::endl;
	lst.remove(25);
	it2 = easyfind(lst, 25);
	if (it2 != lst.end())
		std::cout <<BOLD << GREEN << "Element found: " << RESET << *it2 << std::endl;
	else
		std::cout << BOLD << RED << "Element not found" << RESET << std::endl;
	std::list <int> const lst2(lst);
	std::cout << std::endl << BOLD << CYAN << "Test with list<int> const lst2(lst):" << std::endl;
	std::cout << RESET << "Initial list:" << std::endl;
	for (std::list<int>::const_iterator it = lst2.begin(); it != lst2.end(); ++it)
		std::cout << *it <<std::endl;
	std::cout << "easyfind(49) :" << std::endl;
	it2 = easyfind(lst2, 49);
	if (it2 != lst.end())
		std::cout <<BOLD << GREEN << "Element found: " << RESET << *it2 << std::endl;
	else
		std::cout << BOLD << RED << "Element not found" << std::endl;
	return (0);
}