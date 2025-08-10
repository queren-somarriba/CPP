/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:53:54 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/26 18:13:32 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		return (std::cerr << "Error: Usage: ./btc <infile>" << std::endl, 1);
	BitcoinExchange btc(argv[1]);
	btc.display();
	return (0);
}