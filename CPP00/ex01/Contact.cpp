/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:16:17 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/04 18:48:57 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string const str1, std::string const str2, std::string const str3,
		std::string const str4, std::string const str5) : _first_name(str1),
		_last_name(str2), _nickname(str3), _phone_number(str4), _darkest_secret(str5)
{
}

Contact::~Contact(void)
{
}

void	Contact::set_first_name(std::string const& str)
{
	this->_first_name = str;
}

void	Contact::set_last_name(std::string const& str)
{
	this->_last_name = str;
}

void	Contact::set_nickname(std::string const& str)
{
	this->_nickname = str;
}

void	Contact::set_phone_number(std::string const& str)
{
	this->_phone_number = str;
}

void	Contact::set_darkest_secret(std::string const& str)
{
	this->_darkest_secret = str;
}

std::string Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

void	Contact::display_contact(void) const
{
	std::cout << std::endl;
	std::cout << "First name: " << this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
}
