/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 16:15:42 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("defaultForm"), _is_signed(0), _signed_grade(150), _exec_grade(150) 
{
}

Form::Form(Form const& other) : _name(other._name), _is_signed(other._is_signed),
_signed_grade(other._signed_grade),_exec_grade(other._exec_grade)
{
}

Form::Form(std::string const& name, bool b, unsigned int const grade1, unsigned int const grade2) :
_name(name), _is_signed(b), _signed_grade(Form::_checkGrade(grade1)), _exec_grade(Form::_checkGrade(grade2))
{
}

Form::~Form(void)
{
}

Form& Form::operator=(Form const& other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}

std::string const	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignedStatus() const
{
	return (this->_is_signed);
}

unsigned int	Form::getSignedGrade() const
{
	return (this->_signed_grade);
}

unsigned int	Form::getExecGrade() const
{
	return (this->_exec_grade);
}

unsigned int	Form::_checkGrade(unsigned int const& grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	Form::beSigned(Bureaucrat const& b)
{
	if (this->_signed_grade < b.getGrade())
	{
		std::cerr << b.getName() << " counldn't sign " << this->getName()
		<< " because ";
		throw GradeTooLowException();
	}
	this->_is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream&	operator<<(std::ostream& os, Form const& f)
{
	os << f.getName() << ", is ";
	if (!f.getSignedStatus())
		os << "not ";
	os << "signed, grade required to be signed: " << f.getSignedGrade()
	<< ", grade required to be executed: " << f.getExecGrade()
	<< "." << std::endl;
	return (os);
}