/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:18:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 11:47:25 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		unsigned int		_grade;
		unsigned int		_checkGrade(unsigned int const&) const;
	public:
		/* Copelian Form + parametric constructor */
					Bureaucrat();
					Bureaucrat(std::string const&, unsigned int const&);
					Bureaucrat(Bureaucrat const&);
					~Bureaucrat();
		Bureaucrat&		operator=(Bureaucrat const&);
		/* Member functions */
		void			decrement();
		void			increment();
		/* Getters */
		std::string const&	getName() const;
		unsigned int const&	getGrade() const;
		/* Exceptions */
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream&, Bureaucrat const&);

#endif