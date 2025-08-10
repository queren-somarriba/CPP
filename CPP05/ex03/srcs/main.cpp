/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:34:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 12:23:41 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;

    // Tests avec des formulaires valides
    AForm* form1 = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
    AForm* form2 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    AForm* form3 = someRandomIntern.makeForm("PresidentialPardonForm", "Fry");
    std::cout << std::endl;

    if (form1)
    {
        std::cout << *form1 << std::endl;
        delete form1;
    }
    if (form2)
    {
        std::cout << *form2 << std::endl;
        delete form2;
    }
    if (form3)
    {
        std::cout << *form3 << std::endl;
        delete form3;
    }
    std::cout << std::endl;

    // Test avec un formulaire inconnu
    AForm* form4 = someRandomIntern.makeForm("unknown form", "Target X");
    if (form4)
    {
        std::cout << *form4 << std::endl;
        delete form4;
    }
    return 0;
}