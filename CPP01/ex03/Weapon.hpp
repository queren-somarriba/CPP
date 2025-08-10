/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:31:09 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 15:00:14 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
 	public:
					Weapon(std::string const& str = "");
					~Weapon();
		std::string const&	getType() const;
		void			setType(std::string const& str);
	private:
		std::string		_type;
};

#endif