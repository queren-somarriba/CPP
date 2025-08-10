/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:16:24 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/20 14:28:13 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
# define Contact_HPP

#include <iostream>

class Contact
{
 	public:
		Contact(std::string const str1 = "", std::string const str2 = "", std::string const str3 = "",
			std::string const str4 = "", std::string const str5 = "");
		~Contact(void);

		void		set_first_name(std::string const&);
		void		set_last_name(std::string const&);
		void		set_nickname(std::string const&);
		void		set_phone_number(std::string const&);
		void		set_darkest_secret(std::string const&);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_darkest_secret(void) const;
		void		display_contact(void) const;

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif 
