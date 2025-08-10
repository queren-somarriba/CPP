/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:16:41 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 12:36:27 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main ()
{
	std::string	line;
	PhoneBook	user_phone_book;

	std::getline(std::cin, line);
	while (line.compare("EXIT"))
	{
		if (std::cin.eof())
			break;
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		else if (!line.compare("ADD"))
			user_phone_book.add_contact();
		else if ((!line.compare("SEARCH")) && user_phone_book.display_phonebook())
			user_phone_book.display_contact(user_phone_book.get_contact_index());
		std::getline(std::cin, line);
	}
	return (0);
}
