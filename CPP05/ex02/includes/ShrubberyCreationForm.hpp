/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 15:38:30 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		/* Canonical ShrubberyCreationForm */
					ShrubberyCreationForm();
					ShrubberyCreationForm(ShrubberyCreationForm const&);
					ShrubberyCreationForm(std::string const& target);
					~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const&);
		/* Member Functions */
		void			execute(Bureaucrat const& executor) const;
};

#endif 