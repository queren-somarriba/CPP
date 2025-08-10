/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/04 12:28:14 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 0, 72, 45, "no_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) : AForm(other)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("RobotomyRequestForm", 0, 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::cout << "Bzzzz Bzzzz Bzzzz !!" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed..." << std::endl;
}