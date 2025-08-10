/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:29:36 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 12:29:38 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie	z1 = Zombie("zombzomb");
	z1.annonce();
	z1.randomChump("zombeaver");

	Zombie *z2 = z1.newZombie("zombastic");
	z2->annonce();
	delete z2;
	return (0);
}