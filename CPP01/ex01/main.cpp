/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:30:20 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 14:51:01 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
	Zombie tmp;
	int	size = 432;
	Zombie *arr = tmp.zombieHorde(size, "zombHorde");
	for(int i = 0; i < size; i++)
	{
		std::cout << i << " -> ";
		arr[i].annonce();
	}
	delete [] arr;
	return (0);
}