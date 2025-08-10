/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:32 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 12:32:33 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
	std::string level;
	Harl	leH;

	std::cout << "Please enter a complain level: " << std::endl;
	std::cin >> level;
	while (!std::cin.eof())
	{
		leH.complain(level);
		std::cout << "Any other complain? " << std::endl;
		std::cin >> level;
	}
	return (0);
}