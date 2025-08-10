/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:07:53 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/18 17:16:40 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include  <string>

class Intern
{
	public:
			Intern();
			Intern(Intern const&);
			~Intern();
		Intern&	operator=(Intern const&);
		AForm*	makeForm(std::string name, std::string target) const;
};

