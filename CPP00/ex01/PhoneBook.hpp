/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:17:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/20 14:27:55 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
 	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		add_contact(void);
		bool		display_phonebook(void) const;
		void		display_contact(unsigned int const& index) const;
		unsigned int	get_contact_index(void) const;

	private:
		Contact		_contact_array[8];
		unsigned int	_number_contact;
		bool		_full;

		void		_format(std::string const& str) const;
		std::string	_prompt(std::string const& str, std::string line) const;
};

#endif 
