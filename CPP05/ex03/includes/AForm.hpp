/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/16 17:57:39 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;

class AForm
{
	protected:
		std::string const	_name;
		bool			_is_signed;
		unsigned int const	_signed_grade;
		unsigned int const	_exec_grade;
		unsigned int		_checkGrade(unsigned int const&);
		std::string const	_target;
	public:
		/* Canonical AForm */
					AForm();
					AForm(AForm const&);
					AForm(std::string const&, bool, unsigned int const, unsigned int const, std::string target);
		virtual			~AForm();
		AForm&			operator=(AForm const&);
		/* Exceptions */
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
			class UnsignedForm : public std::exception
		{
			virtual const char* what() const throw();
		};
		/* Getters */
		std::string const	getName() const;
		bool			getSignedStatus() const;
		unsigned int		getSignedGrade() const;
		unsigned int		getExecGrade() const;
		std::string const	getTarget() const;
		/* Member Functions */
		void			beSigned(Bureaucrat const&);
		virtual void		execute(Bureaucrat const& executor) const = 0;
};

std::ostream&		operator<<(std::ostream&, AForm const&);

#endif 