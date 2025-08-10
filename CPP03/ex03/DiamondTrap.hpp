/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:42:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/26 14:26:28 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
	/* Constructors */
				DiamondTrap(std::string const&);
				DiamondTrap(DiamondTrap const&);
	/* Destructor */
				~DiamondTrap();
	/* Assignment operator */
		DiamondTrap&	operator=(DiamondTrap const &);
	/* Member function */
		void		whoAmI(void) const;
		using 		ScavTrap::attack;
};

#endif 