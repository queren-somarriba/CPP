/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:30:14 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/11 15:53:45 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
 	public:
			Zombie(void);
			~Zombie(void);
		void	annonce(void) const;
		Zombie*	zombieHorde(int N, std::string name);

	private:
		std::string	_name;
};

#endif 