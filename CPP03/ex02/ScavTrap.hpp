/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:31:40 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 18:31:41 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	public:
	/* Constructors */
				ScavTrap(ScavTrap const&);
				ScavTrap(std::string const&);
	/* Destructor */
				~ScavTrap(void);
	/* Assignment operator */
		ScavTrap&	operator=(ScavTrap const&);
	/* Member functions */
		void		attack(std::string const&);
		void		guardGate(void) const;
};



#endif 