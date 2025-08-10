/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:30 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 12:32:31 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

Harl::Harl(void)
{
	return ; 
}

Harl::~Harl(void)
{
	return ;
}

void Harl::_debug(void) const
{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::_info(void) const
{
	std::cout << INFO_MSG << std::endl;
}

void Harl::_warning(void) const
{
	std::cout << WARNING_MSG << std::endl;
}

void Harl::_error(void) const
{
	std::cout << ERROR_MSG << std::endl;
}

void	Harl::complain(std::string const& level) const
{
	std::string	arr_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[])(void) const = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	for (int i = 0; i < 4; i++)
	{
		if (!arr_lvl[i].compare(level))
		{
			(this->*f[i])();
			return ;
		}
		
	}
	std::cout << "Probably complaining about insignificant problem" << std::endl;
}