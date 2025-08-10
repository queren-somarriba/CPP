/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:55:33 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:02:44 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("Ruby");

	dt.attack("target");
    	dt.takeDamage(20);
  	  dt.beRepaired(7);
	dt.highFivesGuys();
	dt.guardGate();
	dt.whoAmI();

	return 0;
}

