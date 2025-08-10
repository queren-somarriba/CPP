/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:36:53 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/23 16:50:31 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

#define GREEN   "\033[32m"
#define RED	"\033[31m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

int main()
{
	/* 1 */
	std::cout << '\n' << BOLD << CYAN << "1 - Subject Tests:" << RESET << std::endl;
	std::cout << GREEN << "-> With MutantStack:" << RESET << '\n';
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << GREEN << "-> With std::list<int>:" << RESET << '\n';
		std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator itt = lst.begin();
	std::list<int>::iterator itte = lst.end();
	++itt;
	--itt;
	while (itt != itte)
	{
		std::cout << *itt << std::endl;
		++itt;
	}
	std::cout << GREEN << "-> With std::vector<int>:" << RESET << '\n';
		std::vector<int> v;
	v.push_back(5);
	v.push_back(17);
	std::cout << v.back() << std::endl;
	v.pop_back();
	std::cout << v.size() << std::endl;
	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	v.push_back(0);
	std::vector<int>::iterator ittt = v.begin();
	std::vector<int>::iterator ittte = v.end();
	++ittt;
	--ittt;
	while (ittt != ittte)
	{
		std::cout << *ittt << std::endl;
		++ittt;
	}
	/* 2 */
	std::cout << '\n' << BOLD << CYAN << "2 - Tests on MutantStack<std::string>:" << RESET << std::endl;
	MutantStack<std::string> mstack2;
	mstack2.push("hello");
	mstack2.push("darkness");
	mstack2.push("my old friend");
	for(MutantStack<std::string>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	mstack2.pop();
	for(MutantStack<std::string>::iterator it = mstack2.begin(); it != mstack2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	/* 3 */
	std::cout << '\n' << BOLD << CYAN << "3 - Tests on MutantStack<std::vector<std::string> >:" << RESET << std::endl;
	MutantStack<std::vector<std::string> > mstack3;
	std::vector<std::string> vect;
	vect.push_back("1 - uno");
	vect.push_back("2 - dos");
	vect.push_back("3 - tres");
	mstack3.push(vect);
	vect.clear();
	vect.push_back("uno - one");
	vect.push_back("dos - two");
	vect.push_back("tres - three");
	mstack3.push(vect);
	for(MutantStack<std::vector<std::string> >::iterator it = mstack3.begin(); it != mstack3.end(); ++it)
	{
		for(std::vector<std::string>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
			std::cout << *it2 << '\n';
	}
	mstack3.pop();
	mstack3.pop();
	for(MutantStack<std::vector<std::string> >::iterator it = mstack3.begin(); it != mstack3.end(); ++it)
	{
		for(std::vector<std::string>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
			std::cout << *it2 << '\n';
	}
	/* 4 */
	std::cout << '\n' << BOLD << CYAN << "4 - Test with const MutantStack:" << RESET << std::endl;
	const MutantStack<int> constStack = mstack;
	for(MutantStack<int>::const_iterator it4 = constStack.begin(); it4 != constStack.end(); ++it4)
		std::cout << *it4 << '\n';
	MutantStack<int>::const_iterator it4 = constStack.begin();
	it4++;
	std::cout << "Atfer it4++: "<< *it4 << '\n';
	//constStack.push(42); //shouldn't compile
	/* 5 */
	std::cout << '\n' << BOLD << CYAN << "5 - Test with reverse_iterator MutantStack:" << RESET << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << '\n';
	return 0;
}
