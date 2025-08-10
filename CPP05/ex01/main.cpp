/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:37 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 12:01:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
    // ANSI color codes
    const char *RESET = "\033[0m";
    const char *RED = "\033[31m";
    const char *GREEN = "\033[32m";
    const char *YELLOW = "\033[33m";
    const char *BLUE = "\033[34m";
    const char *MAGENTA = "\033[35m";
    const char *CYAN = "\033[36m";

    // Test case: Valid Bureaucrat and Form creation and use of beSigned
    try 
    {
        std::cout << CYAN << "=== Test: Valid Bureaucrat and Form ===" << RESET << std::endl;

        Bureaucrat bureaucrat("Mike", 99);
        std::cout << GREEN << bureaucrat << RESET << std::endl;

        Form form("Formulaire 1", 0, 99, 150);
        std::cout << YELLOW << "Formulaire 1 initial state:" << RESET << std::endl
                  << form << std::endl;

        bureaucrat.signForm(form);
        std::cout << BLUE << form << RESET << std::endl;

        std::cout << MAGENTA << "Decrement Mike!" << RESET << std::endl;
        bureaucrat.decrement();

        bureaucrat.signForm(form);
        std::cout << GREEN << bureaucrat << RESET
                  << BLUE << form << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << std::endl
                  << CYAN << "=== Test: Create Form with too high grade required to sign ===" << RESET << std::endl;

        Form form2("formulaire 2", 0, 0, 0);
        std::cout << BLUE << form2 << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    try
    {
        std::cout << std::endl
                  << CYAN << "=== Test: Create Form with too low grade required to execute ===" << RESET << std::endl;

        Form form3("formulaire 3", 0, 1, 151);
        std::cout << BLUE << form3 << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}