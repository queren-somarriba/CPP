/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:18:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 16:17:40 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("defaultBureaucrate"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string const& name, unsigned int const& grade)
: _name(name), _grade(grade)
{
	this->_grade = Bureaucrat::_checkGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : _name(other._name), _grade(other._grade)
{
}
Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

void	Bureaucrat::decrement()
{
	Bureaucrat::_checkGrade(this->_grade + 1);
	this->_grade++;
}

void	Bureaucrat::increment()
{
	Bureaucrat::_checkGrade(this->_grade - 1);
	this->_grade--;
}

std::string const&	Bureaucrat::getName() const
{
	return (this->_name);
}

unsigned int const&	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& b)
{
	os << b.getName() << ", bureaucrat grade "
		<< b.getGrade() << "." << std::endl;
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Invalid Grade: Grade is too high");
}

const char*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Invalid Grade: Grade is too low");
}

unsigned int	Bureaucrat::_checkGrade(unsigned int const& grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	form.execute(*this);
}

void	Bureaucrat::signForm(AForm& f) const
{
	try
	{
		f.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return;
	}
	std::cout << this->_name << " signed " << f.getName() <<std::endl;
}
