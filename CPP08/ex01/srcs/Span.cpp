/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:56:09 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/22 18:08:20 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Span.hpp"

/* Canonical form + Parametric constructor */
Span::Span() : _maxSize(1)
{
}

Span::Span(Span const& other) : _maxSize(other._maxSize), _v(other._v)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::~Span()
{
	this->_v.clear();
}

Span&	Span::operator=(Span const& other)
{
	if (this != &other)
	{
		this->_maxSize  = other._maxSize;
		this->_v.clear();
		this->_v = other._v;
	}
	return (*this);
}

/* Getters */
unsigned int	Span::getSize() const
{
	return (this->_v.size());
}

int	Span::getVal(unsigned int index) const
{
	std::vector<int>::const_iterator it = this->_v.begin();
	if (index < this->_maxSize && it != this->_v.end())
		return (this->_v[index]);
	else
		throw OutOfRangeIndex();
}

std::vector<int>::iterator	Span::getIterator(unsigned int index)
{
	if (index < this->_v.size())
	{
		std::vector<int>::iterator it = this->_v.begin();
		for(unsigned int i = 0; i < index; i++)
			it++;
		return (it);
	}
	else
		throw OutOfRangeIndex();
}

/* Member functions */
void	Span::addNumber(int const& nb)
{
	if (this->_v.size() + 1 <= this->_maxSize)
		this->_v.push_back(nb);
	else
		throw OutOfRangeIndex();
}

long	Span::shortestSpan() const /* unsigned int (val retour)*/
{
	if (this->_v.size() > 1)
	{
		long shortest = this->longestSpan();
		std::vector<int> tmp = this->_v;
		std::vector<int>::iterator begin = tmp.begin();
		std::vector<int>::iterator end = tmp.end();
		std::sort(begin, end);
		for(unsigned int i = 0; i < tmp.size() - 1; ++i)
			shortest = std::min(shortest, std::labs(tmp[i] - tmp[i + 1]));
		return (shortest);
	}
	else
		throw NoSpanPossible();
}

long	Span::longestSpan() const
{
	if (this->_v.size() > 1)
	{
		std::vector<int>::const_iterator begin = this->_v.begin();
		std::vector<int>::const_iterator end = this->_v.end();
		long max = *std::max_element(begin, end);
		long min = *std::min_element(begin, end);
		return (max - min);
	}
	else
		throw NoSpanPossible();
}

static int RandomNumber ()/* test avec int_max */
{
	return (std::rand() % std::numeric_limits<int>::max());
}

void	Span::insert(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (first == last)
		return;
	std::srand(static_cast<unsigned>(std::time(0)));
	if (first < this->_v.begin() || last > this->_v.end())
		throw OutOfRangeIndex();
	 std::generate(first, last, RandomNumber);
}

void Span::fillRandomN(unsigned int N)
{
	if (this->_v.size() + N > this->_maxSize)
		throw OutOfRangeIndex();
	std::srand(static_cast<unsigned>(std::time(0)));
	for (unsigned int i = 0; i < N; ++i)
		this->_v.push_back(RandomNumber());
}

/* Excepetions */
const char* Span::OutOfRangeIndex::what() const throw()
{
	return ("Can't access an out of range index");
}

const char*Span::NoSpanPossible::what() const throw()
{
	return ("Not enough element to compute a span!");
}

/* Insertion operator */
std::ostream&	operator<<(std::ostream& os, Span const& sp)
{
	for (unsigned int i = 0; i < sp.getSize(); i++)
		os << sp.getVal(i) << " ";
	return (os);
}