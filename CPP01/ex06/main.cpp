/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:44 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 12:32:44 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Harl leH;

		leH.filter(argv[1]);
	}
	else
	{
		std::cout << "Usage: ./harlFilter <str>" << std::endl;
		return (1);
	}
	return (0);
}