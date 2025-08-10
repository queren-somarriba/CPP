/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:17:16 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 12:59:00 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_number_contact = 0;
	this->_full = false;
	return ; 
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string	PhoneBook::_prompt(std::string const& str, std::string line) const
{
	std::cout << "Please enter contact's " << str << ":" << std::endl;
	std::getline(std::cin, line);
	while(line.empty())
	{
		if (std::cin.eof())
			return ("");
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		std::cout << "Please enter contact's " << str << ":" << std::endl;
		std::getline(std::cin, line);
	}
	return (line);
}

unsigned int	PhoneBook::get_contact_index(void) const
{
	std::string	line = "hello";
	size_t		i;

	i = 0;
	while (line[i])
	{
		while (line[i] == '0' && line.size() > 1)
			line = line.substr(1, line.size() - 1);
		if (!isdigit(line[i]))
		{
			line = _prompt("index", line);
			if (!line.compare(""))
				return (0);
			i = -1;
		}
		else if (line.size() > 1 || line[i] < '1' || (this->_full && line[i] > '8') ||
			(!this->_full && line[i] > static_cast<int>(this->_number_contact + '0')))
		{
			std::cerr << "Error: Invalid index!" << std::endl;
			line = _prompt("index", line);
			if (!line.compare(""))
				return (0);
			i = -1;
		}
		else
			break;
		i++;
	}
	return (line[i] - '0');
}

void	PhoneBook::add_contact(void)
{
	std::string	line;

	line = _prompt("first name", line);
	if (!line.compare(""))
		return;
	this->_contact_array[this->_number_contact].set_first_name(line);
	line = _prompt("last name", line);
	if (!line.compare(""))
		return;
	this->_contact_array[this->_number_contact].set_last_name(line);
	line = _prompt("nickname", line);
	if (!line.compare(""))
		return;
	this->_contact_array[this->_number_contact].set_nickname(line);
	line = _prompt("phone_number", line);
	if (!line.compare(""))
		return;
	this->_contact_array[this->_number_contact].set_phone_number(line);
	line = _prompt("darkest secret", line);
	if (!line.compare(""))
		return;
	this->_contact_array[this->_number_contact].set_darkest_secret(line);
	this->_number_contact++;
	if (this->_number_contact >= 8)
		this->_full = true;
	this->_number_contact %= 8;
	return ;
}

void	PhoneBook::_format(std::string const& str) const
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << str;
}

bool	PhoneBook::display_phonebook() const
{
	unsigned int	index;

	index = 0;
	std::cout << std::endl;
	if (!this->_full && this->_number_contact <= 0)
	{
		std::cerr << "No contact add to this phone book yet" << std::endl;
		return (false);
	}
	while((!this->_full && index < this->_number_contact) || (this->_full && index < 8))
	{
		std::cout << std::setw(10) << index + 1 << "|";
		_format(this->_contact_array[index].get_first_name());
		std::cout << "|";
		_format(this->_contact_array[index].get_last_name());
		std::cout << "|";
		_format(this->_contact_array[index].get_nickname());
		std::cout << std::endl;
		index++;
	}
	return (true);
}

void	PhoneBook::display_contact(unsigned int const& index) const
{
	if (index == 0)
		return;
	this->_contact_array[index - 1].display_contact();
}
