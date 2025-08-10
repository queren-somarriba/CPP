/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 14:55:37 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		/* Canonical PresidentialPardonForm */
					PresidentialPardonForm();
					PresidentialPardonForm(PresidentialPardonForm const&);
					PresidentialPardonForm(std::string const& target);
					~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(PresidentialPardonForm const&);
		/* Member Functions */
		void			execute(Bureaucrat const& executor) const;

};

#endif 