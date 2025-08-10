/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:08:07 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 17:48:22 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const& other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(Intern const& other)
{
	(void)other;
	return (*this);
}

static AForm* newPresidentialPardonForm(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

static AForm* newShrubberyCreationForm(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* newRobotomyRequestForm(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target) const
{
	std::string	arr_names[3] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
	AForm* (*f[])(std::string const&) = {&newPresidentialPardonForm, &newShrubberyCreationForm, &newRobotomyRequestForm};
	for (int i = 0; i < 3; i++)
	{
		if(!arr_names[i].compare(name))
		{
			std::cout << "Intern creates " << name << std::endl;
			return (f[i](target));
		}
	}
	std::cerr << "Sorry, " << name << " form doesn't exist..." << std::endl;
	return (NULL);
}