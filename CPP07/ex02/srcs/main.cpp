/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:54:25 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/26 18:20:03 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <cstdlib>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

int	main()
{
	try
	{
	    // Test 1
        Array<int> a;
        std::cout << BOLD << GREEN << "Test 1 - " << BOLD << CYAN << "Default constructor: " << RESET << "Array<int> a; -> size: " << GREEN << a.size() << RESET << ", a[0]= " << GREEN << a[0] << RESET << std::endl;
    }
	catch (const std::exception& e)
	{
		std::cout << BOLD << RED << "Caught exception: " << e.what() << std::endl;
    }
    try
    {
        //Test 2
        Array<float> b(5);
        std::cout << BOLD << GREEN << "Test 2 - " << BOLD << CYAN << "Parametrized constructor: " << RESET  << "Array<float> b(5); -> size: " << GREEN << b.size() << std::endl;
        std::cout << RESET << "Initial values of b:" << std::endl;
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" <<  i << "] = " << GREEN << b[i] << RESET << std::endl;

        // Test 3
        for (unsigned int i = 0; i < b.size(); ++i)
            b[i] = i * i;
        std::cout << BOLD << GREEN << "Test 3 - " << CYAN << "Change b values:" << RESET << std::endl;
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << "b[" << i << "] = " << GREEN  << b[i] << RESET << std::endl;

        // Test 4
        Array<float> c(b);
        std::cout << BOLD << GREEN << "Test 4 - " << BOLD << CYAN << "Copy constructor: " << RESET  << "Array<int> c(b); -> size: " << c.size() << std::endl;
        for (unsigned int i = 0; i < c.size(); ++i)
            std::cout << "c[" << i << "] = " << GREEN  << c[i] << RESET << std::endl;
        
        // Test 5
        c[0] = 3.14;
        std::cout << BOLD << GREEN << "Test 5 - " << RESET << "After modifying c[0] = 3.14" << std::endl;
        std::cout << "b[0] = " << GREEN << b[0] << RESET << " (should be unchanged)" << std::endl;
        std::cout << "c[0] = " << GREEN << c[0] << RESET << std::endl;

        // Test 6
        Array<float> const e(b);
        std::cout << BOLD << GREEN << "Test 6 - " << BOLD << CYAN << "Const array element access: " << RESET  << "Array<int> const d(b); -> size: " << e.size() << std::endl;
        for (unsigned int i = 0; i < e.size(); ++i)
            std::cout << "e[" << i << "] = " << GREEN  << e[i] << RESET << std::endl;

        // Test 7
        Array<float> f;
        f = b;
        std::cout << BOLD << GREEN << "Test 7 - " << BOLD << CYAN << "Operator= : " << RESET  << "f = b -> size: " << f.size() << std::endl;
        for(unsigned int i = 0; i < f.size(); ++i)
            std::cout << "f[" << i << "] = " << GREEN  << f[i] << RESET << std::endl;
        f[1] = 42.42;
        std::cout << "After modifying d[1] = 42.42" << std::endl;
        std::cout << "b[1] = " << GREEN << b[1] << RESET << " (should be unchanged)" << std::endl;
        std::cout << "d[1] = " << GREEN << f[1] << RESET << std::endl;

        // Test 8
        std::cout << BOLD << GREEN << "Test 8 - " << BOLD << CYAN << "Access out of bounds:" << std::endl;
        try
        {
		    std::cout << RESET << GREEN << b[42] << RESET << std::endl;
        }
	    catch (const std::exception& e)
	    {
		    std::cout << BOLD << RED << "Caught exception: " << e.what() << std::endl;
        }

        // Test 9
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "Hola";
        strArray[2] = "Hi";
        std::cout << BOLD << GREEN << "Test 9 - " << BOLD << CYAN << "Array of std::string : " << RESET << "Array<std::string>:" << std::endl;
        for (unsigned int i = 0; i < strArray.size(); ++i)
            std::cout << "strArray[" << i << "] = " << GREEN << strArray[i] << RESET << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << BOLD << RED << "Unhandled exception: " << e.what() << std::endl;
        }
	return (0);
}


