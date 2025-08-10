/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:53:59 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/02 14:54:02 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	iter(T* array, size_t len, void (f)(T&))
{
	if (array)
	{
		for (size_t i = 0; i < len; ++i)
			f(array[i]);
	}
}

template<typename T>
void	iter(T* array, size_t len, void (f)(T const&))
{
	if (array)
	{
		for (size_t i = 0; i < len; ++i)
			f(array[i]);
	}
}