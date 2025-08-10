/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:56:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/18 18:50:07 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>
#include <iostream>

class Span
{
	public:
		/* Canonical Form*/
							Span();
							Span(Span const& other);
							~Span();
		Span&					operator=(Span const& other);
		/* Parametric Constructor */
							Span(unsigned int N);
		/* Member functions */
		void					addNumber(int const& nb);
		long					shortestSpan() const;
		long					longestSpan() const;
		void					fillRandomN(unsigned int N);
		void					insert(std::vector<int>::iterator, std::vector<int>::iterator);
		/* Getters */
		unsigned int				getSize() const;
		int					getVal(unsigned int index) const;
		std::vector<int>::iterator		getIterator(unsigned int index);

	private:
		unsigned int				_maxSize;
		std::vector<int>			_v;
		/* exceptions */
		class OutOfRangeIndex : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class NoSpanPossible : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream&, Span const&);