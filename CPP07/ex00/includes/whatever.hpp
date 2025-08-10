/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:53:44 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/02 14:53:49 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void		swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const&	min(T const& a, T const& b)
{
	return ((a <= b) ? a : b);
}

template<typename T>
T const&	max(T const& a, T const& b)
{
	return ((a >= b) ? a : b);
}
