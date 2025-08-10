/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:21:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 14:55:54 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		/* Canonical RobotomyRequestForm */
					RobotomyRequestForm();
					RobotomyRequestForm(RobotomyRequestForm const&);
					RobotomyRequestForm(std::string const& target);
					~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(RobotomyRequestForm const&);
		/* Member Functions */
		void			execute(Bureaucrat const& executor) const;

};

#endif 