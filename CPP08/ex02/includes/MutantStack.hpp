/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:36:37 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/23 15:53:45 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
					MutantStack();
					MutantStack(MutantStack const& other);
		MutantStack 		&operator=(MutantStack const& other);
					~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		iterator 		begin(void);
		iterator 		end(void);
		const_iterator 		begin(void) const;
		const_iterator 		end(void) const;
		reverse_iterator	rend(void);
		reverse_iterator	rbegin(void);
};

#include "MutantStack.tpp"