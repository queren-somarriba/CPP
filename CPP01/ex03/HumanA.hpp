/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:31:41 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 14:58:55 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
 	public:
				HumanA(std::string const& name, Weapon& weapon);
				~HumanA();
		void		attack(void) const;
	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif 