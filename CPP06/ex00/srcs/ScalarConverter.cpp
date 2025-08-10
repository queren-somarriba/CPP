/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:17:25 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 12:48:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

static bool isCharLiteral(std::string const& literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isFloat(std::string const& literal)
{
    if (literal == "+inff" || literal == "-inff" || literal == "nanf")
    return (true);
    char* endptr;
    double val = std::strtod(literal.c_str(), &endptr);
    return (*endptr == 'f' && *(endptr + 1) == 0 && val >= -std::numeric_limits<float>::max() && val <= std::numeric_limits<float>::max());
}

static bool isDouble(std::string const& literal)
{
    if (literal == "+inf" || literal == "-inf" || literal == "nan")
        return (true);
    char* endptr;
    long double val = std::strtold(literal.c_str(), &endptr);
    return (*endptr == '\0' && val >= -std::numeric_limits<double>::max() && val <= std::numeric_limits<double>::max());
}

static bool isInt(std::string const& literal)
{
    char* endptr;
    long val = std::strtol(literal.c_str(), &endptr, 10);
    return (*endptr == '\0' && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

static void displayConvertions(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(value)))
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    std::cout << "float: ";
    float float_value = static_cast<float>(value);
    std::cout << float_value;
    if (float_value == static_cast<int>(float_value) && value < 1e+06 && value > -1e+06)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: ";
    std::cout << value;
    if (value == static_cast<int>(value) && value < 1e+06 && value > -1e+06) 
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string const& literal)
{
    double value = 0.0;

    if (isCharLiteral(literal))
        value = static_cast<double>(literal[1]);
    else if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    else if (isDouble(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "Invalid input." << std::endl;
        return;
    }
    displayConvertions(value);
}
