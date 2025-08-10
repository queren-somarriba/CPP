/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 17:01:50 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("defaultAForm"), _is_signed(0), _signed_grade(150), _exec_grade(150), _target("")
{
}

AForm::AForm(AForm const& other) : _name(other._name), _is_signed(other._is_signed),
_signed_grade(other._signed_grade), _exec_grade(other._exec_grade), _target(other._target)
{
}

AForm::AForm(std::string const& name, bool b, unsigned int const grade1, unsigned int const grade2, std::string target) :
_name(name), _is_signed(b), _signed_grade(AForm::_checkGrade(grade1)), _exec_grade(AForm::_checkGrade(grade2)), _target(target)
{
	
}

AForm::~AForm(void)
{
}

AForm& AForm::operator=(AForm const& other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}

std::string const	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSignedStatus() const
{
	return (this->_is_signed);
}

unsigned int	AForm::getSignedGrade() const
{
	return (this->_signed_grade);
}

unsigned int	AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

std::string const	AForm::getTarget() const
{
	return (this->_target);
}

unsigned int	AForm::_checkGrade(unsigned int const& grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	AForm::beSigned(Bureaucrat const& b)
{
	if (this->_signed_grade < b.getGrade())
	{
		std::cerr << b.getName() << " counldn't sign " << this->getName()
		<< " because ";
		throw GradeTooLowException();
	}
	this->_is_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}
const char*	AForm::UnsignedForm::what() const throw()
{
	return ("Form isn't signed.");
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!this->_is_signed)
	{
		std::cerr << executor.getName() << " can't execute "
		<< this->_name << " because: ";
		throw UnsignedForm();
	}
	if (executor.getGrade() > this->_exec_grade)
	{
		std::cerr << executor.getName() << " can't execute "
		<< this->_name << " because: ";
		throw GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream& os, AForm const& f)
{
	os << f.getName() << ", is ";
	if (!f.getSignedStatus())
		os << "not ";
	os << "signed, grade required to be signed: " << f.getSignedGrade()
	<< ", grade required to be executed: " << f.getExecGrade()
	<< ", form target is " << f.getTarget()
	<< "." << std::endl;
	return (os);
}