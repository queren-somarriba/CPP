/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:30:16 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/26 19:16:38 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int jacb(int i)
{
	long res;
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	res = jacb(i - 1) + (2 * jacb(i - 2));
	if (res > std::numeric_limits<int>::max())
		throw tooLargeNumber();
	return (res);
}

int	getVal(std::string const& str)
{
	char*	endptr;
	long	val = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr == '\0' && val >= 0.0f && val <= std::numeric_limits<unsigned int>::max())
		return (val);
	if (val < 0)
		throw negativNumber();
	if (val > std::numeric_limits<int>::max())
		throw tooLargeNumber();;
	throw wrongArgument();
}

int	biSearchMiddle(int left, int right, int lvl)
{
	int middle = (right + left) / 2;
	while (middle % lvl != lvl - 1)
		middle--;
	return (middle);
}


const char* wrongArgument::what() const throw()
{
	return ("Error: Invalid argument");
}

const char* tooLargeNumber::what() const throw()
{
	return ("Error: number too large");
}

const char* negativNumber::what() const throw()
{
	return ("Error: negative number");
}

const char* emptyArg::what() const throw()
{
	return ("Error: empty argument");
}
