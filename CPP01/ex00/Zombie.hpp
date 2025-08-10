/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:29:41 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/11 15:52:03 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
 	public:
			Zombie(std::string const& str);
			~Zombie(void);
		void	annonce(void) const;
		Zombie*	newZombie(std::string name);
		void	randomChump(std::string name);
	private:
		std::string	_name;
};

#endif 