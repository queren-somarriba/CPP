/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:49:43 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 19:36:17 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap
{
	public:
	/* Constructors */
				FragTrap(FragTrap const&);
				FragTrap(std::string const&);
	/* Destructor */
				~FragTrap(void);
	/* Assignment operator */
		FragTrap&	operator=(FragTrap const&);
	/* Member functions */
		void		attack(std::string const&);
		void		highFivesGuys
		
		
		
		
		
		
		
		
		
		
		
		
		(void) const;
};

#endif 