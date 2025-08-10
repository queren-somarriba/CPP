/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:17:27 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/25 15:26:30 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
	private:
					ScalarConverter();
					ScalarConverter(const ScalarConverter&);
		ScalarConverter&	operator=(const ScalarConverter&);
					~ScalarConverter();
	public:
		static void		convert(std::string const& literal);
 };