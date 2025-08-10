/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:35:36 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 18:05:57 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		/* Constructors */
				ClapTrap(std::string const& name);
				ClapTrap(ClapTrap const&);
		/* Destructor */
				~ClapTrap();
		/* Assignment operator */
		ClapTrap&	operator=(ClapTrap const&);
		/* Member functions */
		void		attack(const std::string&);
		void		takeDamage(unsigned int);
		void		beRepaired(unsigned int);
};

#endif 