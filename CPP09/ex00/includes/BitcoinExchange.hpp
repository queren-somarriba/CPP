/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:52:16 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/21 19:09:52 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include <sys/stat.h> 
#include <fstream>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <ctime>

class BitcoinExchange
{
	public:
		/* Parametric Constructor + destructor */
					BitcoinExchange(std::string file_name);
					~BitcoinExchange();
		/* Member functions */
		int			checkFiles();
		int			makeDataMap();
		float			closestVal(std::string const& key);
		int			printLine(std::string line);
		int			display();
	private:
					BitcoinExchange();
					BitcoinExchange(BitcoinExchange&);
		BitcoinExchange&	operator=(BitcoinExchange&);
		std::string const		_file_name;
		std::ifstream			_infile;
		std::ifstream			_dataBase;
		std::map<std::string, float>	_data_map;
};