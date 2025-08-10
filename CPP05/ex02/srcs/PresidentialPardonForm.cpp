/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 15:13:02 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 0, 25, 5, "no_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) : AForm(other)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("PresidentialPardonForm", 0, 25, 5, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}