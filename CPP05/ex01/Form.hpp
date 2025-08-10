/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/04 12:24:11 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool			_is_signed;
		unsigned int const	_signed_grade;
		unsigned int const	_exec_grade;
		unsigned int		_checkGrade(unsigned int const&);
	public:
		/* Canonical Form */
					Form();
					Form(Form const&);
					Form(std::string const&, bool, unsigned int const, unsigned int const);
					~Form();
		Form&			operator=(Form const&);
		/* Exceptions */
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		/* Getters */
		std::string const	getName() const;
		bool			getSignedStatus() const;
		unsigned int		getSignedGrade() const;
		unsigned int		getExecGrade() const;
		/* Member Functions */
		void			beSigned(Bureaucrat const&);
};

std::ostream&	operator<<(std::ostream&, Form const&);

#endif 