/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:30:43 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 12:30:48 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR  = &str;
	std::string& stringREF = str;
	
	std::cout << "memory adress of  the stringVAR: " << &str << std::endl;
	std::cout << "memory adress held by stringPTR: " << stringPTR << std::endl;
	std::cout << "memory adress held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl << "value of the stringVAR: " << str << std::endl;
	std::cout << "value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of the stringREF: " << stringREF << std::endl;
	return (0);
}