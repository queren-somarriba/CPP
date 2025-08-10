/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:30:19 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/27 16:12:47 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <exception>
#include <sys/time.h>

#define ERROR_USAGE "Error: Usage: ./PmergeMe nbr1 nbr2 ... nbrn - or ./PmergeMe \"nbr1 nbr2 ... nbrn\""

/* Exceptions */
class wrongArgument : public std::exception
{
	public :
		virtual const char* what() const throw();
};

class tooLargeNumber : public std::exception
{
	public :
		virtual const char* what() const throw();
};

class negativNumber : public std::exception
{
	public :
		virtual const char* what() const throw();
};

class emptyArg : public std::exception
{
	public :
		virtual const char* what() const throw();
};

/* Functions */
int	jacb(int i);

int	getVal(std::string const& str);

int	biSearchMiddle(int left, int right, int lvl);

/* Templates */
template<typename T>
void	printNbrLst(T const& nbrs)
{
	for (size_t i = 0; i < nbrs.size(); ++i)
		std::cout << nbrs[i] << ' ';
	std::cout << std::endl;
}

template<typename T>
T	parse_arguments(int argc, char** argv)
{
	T	nbrs;
	int	i = 0;
	if (argc == 2)
	{
		while (isspace(argv[1][i]))
			++i;
		if (argv[1][i] == '\0')
			throw wrongArgument();
		std::istringstream	iss(argv[1]);
		std::string		val;
		while (iss >> val)
			nbrs.push_back(getVal(val));
	}
	else if (argc > 2)
	{
		for (int j = 1; j < argc; ++j)
		{
			while (isspace(argv[j][i]))
				++i;
			if (argv[j][i] == '\0')
				throw wrongArgument();
			if (argv[j] && *argv[j] != '\0')
				nbrs.push_back(getVal(argv[j]));
		}
	}
	return (nbrs);
}

template<typename T>
void	swapV(T& nbrs, int index1, int index2)
{
	int	swap;
	swap = nbrs[index1];
	nbrs[index1] = nbrs[index2];
	nbrs[index2] = swap;
}

template<typename T>
void    pairSort(T& nbrs)
{
	unsigned int	i, lvl = 1;
	while(lvl <= nbrs.size() / 2)
	{
		i = lvl - 1;
		while(i < nbrs.size() - lvl)
		{
			if (nbrs[i] > nbrs[i + lvl])
				for(unsigned int j = i - lvl + 1; j < i + 1; j++)
					swapV(nbrs, j, j + lvl);
			i = i + 2 * lvl;
		}
		lvl *= 2;
	}
}

template<typename T>
int	biSearch(const T& cont, int target, int lvl)
{
	int	left = lvl - 1;
	int	right = cont.size() - 1;
	while ((right + 1) % lvl != 0)
		--right;
	int	middle;
	while (left <= right)
	{
		middle = biSearchMiddle(left, right, lvl);
		if (middle >= static_cast<int>(cont.size()))
			break;
		if (cont[middle] < target)
			left = middle + lvl;
		else
			right = middle - lvl;
	}
	return (right < 0 ? 0 : right + 1);
}

template<typename T>
void	insertPend(T& main, T& pend, int index, int lvl)
{
	int	pos = biSearch(main, pend[index], lvl);
	if (pend.size() >= static_cast<size_t>(lvl) && index >= lvl - 1)
	{
		typename T::iterator start = pend.begin() + (index - lvl + 1);
		typename T::iterator end = pend.begin() + (index + 1);
		if (start <= end && end <= pend.end())
			main.insert(main.begin() + pos, start, end);
	}
	else if (pend.size() == 1)
		main.insert(main.begin() + pos, pend[0]);
}

template<typename T>
void    makeMainPend(T& nbrs, T& main, T& pend, unsigned int lvl)
{
	main.insert(main.begin(), nbrs.begin(), nbrs.begin() + lvl);
	if (nbrs.size() > 0)
		nbrs.erase(nbrs.begin(), nbrs.begin() + lvl);
	while (nbrs.size() >= 2 * lvl)
	{
		main.insert(main.end(), nbrs.begin(), nbrs.begin() + lvl);
		pend.insert(pend.end(), nbrs.begin() + lvl, nbrs.begin() + (2 * lvl));
		if (nbrs.size() >= 2 * lvl)
			nbrs.erase(nbrs.begin(), nbrs.begin() + (2 * lvl));
	}
	if (nbrs.size() >= lvl)
	{
		main.insert(main.end(), nbrs.begin(), nbrs.begin() + lvl);
		if (nbrs.size() > 0)
			nbrs.erase(nbrs.begin(), nbrs.begin() + lvl);
	}
}

template<typename T>
void	insertPendInMain(T& main, T& pend, unsigned int lvl)
{
	int 			jacb_index;
	typename T::iterator	start, end;
	for (int i = 3; pend.size() / lvl >= static_cast<unsigned int>(jacb(i) - jacb(i - 1)); ++i)
	{
		for(int j = 0; j < jacb(i) - jacb(i - 1); ++j)
		{
			jacb_index = (lvl * ((jacb(i) - jacb(i - 1) - j))) - 1;
			insertPend(main, pend, jacb_index, lvl);
			if ((unsigned)jacb_index >= lvl - 1 && (unsigned)jacb_index <= pend.size())
			{
				if (pend.size() > 1)
				{
					start = pend.begin() + (jacb_index - lvl + 1);
					end = pend.begin() + (jacb_index + 1);
					if (start <= end && end <= pend.end())
						pend.erase(start, end);
					else if (pend.size() == 1)
						pend.clear();
				}
			}
			if (pend.size() == 1)
			{
				insertPend(main, pend, pend.size() - 1, lvl);
				pend.clear();
			}
		}
	}
	for(int i = pend.size() - 1; i > 0; i -= lvl)
	{
		insertPend(main, pend, i, lvl);
		if (pend.size() > 0)
			pend.erase(pend.end() - lvl, pend.end());
	}
	if (pend.size() == 1)
		insertPend(main, pend, 0, lvl);
}

template<typename T>
void	mergeSort(T& nbrs)
{
	T		main, pend;
	unsigned int	lvl = 1;
	while(lvl * 2 <= nbrs.size() / 2)
		lvl *= 2;
	while (lvl >= 1)
	{
		makeMainPend(nbrs, main,pend, lvl);
		insertPendInMain(main, pend, lvl);
		main.insert(main.end(), nbrs.begin(), nbrs.end());
		lvl /= 2;
		nbrs.clear();
		nbrs.insert(nbrs.begin(), main.begin(), main.end());
		main.clear();
		pend.clear();
	}
}

