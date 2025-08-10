/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:54:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 17:57:54 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
unsigned int	_size;
T*		_array;

public:
class WrongIndex : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Index out of range";
		}
};

Array() : _size(0), _array(0)
{
}

Array(unsigned int n): _size(n), _array(new T[n])
{
	for (unsigned int i = 0; i < n; ++i)
		this->_array[i] = T();
}

Array(Array const& other): _size(other._size), _array(new T[other._size])
{
	for(unsigned int i = 0; i < other._size; ++i)
		this->_array[i] = other._array[i];
}
Array&	operator=(Array const& other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[_size];
		for (unsigned int i = 0; i < this->_size; ++i)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

T&	operator[](unsigned int const& idx)
{

	if (idx >= this->_size)
		throw WrongIndex();
	return (this->_array[idx]);
}

T const& operator[](unsigned int const& idx) const
{
	if (idx >= this->_size)
		throw WrongIndex();
	return this->_array[idx];
}

~Array()
{
	delete [] this->_array;
}

unsigned int	size() const
{
	return (this->_size);
}
};