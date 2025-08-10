/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:31:39 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 14:59:12 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
 	public:
				HumanB(std::string const& name);
				~HumanB();
		void		setWeapon(Weapon& Weapon);
		void		attack(void) const;
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif 