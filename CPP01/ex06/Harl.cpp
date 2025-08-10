/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:50 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 12:33:02 by qsomarri         ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl << DEBUG_MSG << std::endl << std::endl;
}

void Harl::_info(void) const
{
	std::cout << "[ INFO ]" << std::endl  << INFO_MSG << std::endl << std::endl;
}

void Harl::_warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl  << WARNING_MSG << std::endl << std::endl;
}

void Harl::_error(void) const
{
	std::cout << "[ ERROR ]" << std::endl  << ERROR_MSG << std::endl << std::endl;
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

void Harl::filter(std::string const& filter) const
{
	int	i = -1;
	std::string arr_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (++i < 4)
	{
		if (!arr_lvl[i].compare(filter))
			break;
	}
	switch (i)
	{
		case (0):
			this->_debug();
		case (1):
			this->_info();
		case (2):
			this->_warning();
		case (3):
			this->_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

