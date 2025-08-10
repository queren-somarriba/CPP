/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:54:50 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/23 14:14:24 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
typename T::const_iterator easyfind(T const& data_struct, int const& i)
{
	return (std::find(data_struct.begin(), data_struct.end(), i));
}