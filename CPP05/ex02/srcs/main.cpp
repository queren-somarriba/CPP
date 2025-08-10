/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:34:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/04 12:34:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);
        Bureaucrat charlie("Charlie", 45);

        std::cout << "---- SHRUBBERY TEST ----" << std::endl;
        ShrubberyCreationForm shrub("home");
        bob.signForm(shrub);
        for (int i = 0; i < 4; i++)
            bob.executeForm(shrub);

        std::cout << "\n---- ROBOTOMY TEST ----" << std::endl;
        RobotomyRequestForm robot("Bender");
        charlie.signForm(robot);
        for (int i = 0; i < 5; ++i) {
            charlie.executeForm(robot);
        }

        std::cout << "\n---- PRESIDENTIAL PARDON TEST ----" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        bob.signForm(pardon);
        bob.executeForm(pardon);

        std::cout << "\n---- EXECUTE WITHOUT SIGNING ----" << std::endl;
        ShrubberyCreationForm notSigned("garden");
        bob.executeForm(notSigned);

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n---- GRADE TOO LOW TO EXECUTE ----" << std::endl;
        Bureaucrat dave("Dave", 140);
        ShrubberyCreationForm shrub2("park");
        dave.signForm(shrub2);
        dave.executeForm(shrub2); // Should throw exception

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}