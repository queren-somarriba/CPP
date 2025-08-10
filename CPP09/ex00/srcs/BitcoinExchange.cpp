/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:20:02 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/21 17:04:53 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file_name) : _file_name(file_name)
{
}
BitcoinExchange::~BitcoinExchange()
{
}

int	BitcoinExchange::checkFiles()
{
	this->_infile.open(this->_file_name.c_str(), std::ifstream::in);
	struct stat path_stat;
	if (this->_infile.fail() || !this->_infile.is_open())
		return (std::cerr << "Error: opening file: " << this->_file_name << std::endl, 1);
	if (stat(this->_file_name.c_str(), &path_stat) != 0)
		return (std::cerr << "Error: cannot access " << this->_file_name << std::endl, 1);
	if (S_ISDIR(path_stat.st_mode))
		return (std::cerr << "Error: " << this->_file_name << " is a directory, not a file." << std::endl, 1);
	this->_dataBase.open("data.csv", std::ifstream::in);
	if (this->_dataBase.fail() || !this->_dataBase.is_open())
		return (std::cerr << "Error: opening file: " << "data.csv" << std::endl, 1);
	if (stat("data.csv", &path_stat) != 0)
		return (std::cerr << "Error: cannot access " << "data.csv" << std::endl, 1);
	if (S_ISDIR(path_stat.st_mode))
		return (std::cerr << "Error: " << "data.csv" << " is a directory, not a file." << std::endl, 1);
	return (0);
}

static bool	isInt(std::string const& str)
{
	char* endptr;
	long val = std::strtol(str.c_str(), &endptr, 10);
	return ((*endptr == '\0' || *endptr == ' ') && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

static int	checkDate(const std::string& str)
{
	std::tm tm = {};
	if (sscanf(str.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) != 3)
		return (std::cerr << "Format invalide ! Attendu : YYYY-MM-DD" << std::endl, 1);
	size_t pos = str.find_last_of("-");
	if (!isInt(str.substr(pos + 1)) || str.substr(pos + 1) == " ")
		return (std::cerr << "Format invalide ! Attendu : YYYY-MM-DD" << std::endl, 1);
	if (tm.tm_mon < 1 || tm.tm_mon > 12 || tm.tm_mday < 1 || tm.tm_mday > 31)
		return (std::cerr << "Date invalide : mois ou jour hors limites." << std::endl, 1);
	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	std::tm tm_check = tm;
	time_t t = mktime(&tm_check);
	if (t == -1)
		return (std::cerr << "Conversion mktime échouée." << std::endl, 1);
	if (tm_check.tm_year != tm.tm_year || tm_check.tm_mon  != tm.tm_mon  || tm_check.tm_mday != tm.tm_mday)
		return (std::cerr << "Date invalide : " << str << std::endl, 1);
	return (0);
}

static float	getVal(std::string const& str)
{
	char*	endptr;
	double	val = std::strtod(str.c_str(), &endptr);
	if (*endptr == '\0' && val >= 0.0f && val <= std::numeric_limits<int>::max())
		return (static_cast<float> (val));
	if (val < 0.0f)
		return (std::cerr << "Error: not a positive number" << std::endl, -1.0f);
	if (val > std::numeric_limits<int>::max())
		return (std::cerr << "Error: too large number" << std::endl, -1.0f);
	return (std::cerr << "Error: bad input" << std::endl, -1.0f);
}

int	BitcoinExchange::makeDataMap()
{
	std::string	line;
	size_t	pos;
	std::string date;
	std::string val;
	std::getline(this->_dataBase, line);
	if (!line.compare("date,exchange_rate"))
		std::getline(this->_dataBase, line);
	while (!this->_dataBase.eof())
	{
		if (this->_dataBase.fail())
			return (this->_dataBase.clear(), 1);
		pos = line.find(",");
		if (pos != std::string::npos)
		{
			date = line.substr(0, pos);
			val = line.substr(pos + 1);
			if (!checkDate(date) && getVal(val) > 0)
			this->_data_map[date] = getVal(val); 
		}
		else
			std::cerr << "Error: Wrong format" << std::endl;
		std::getline(this->_dataBase, line);
	}
	return (0);
}

float BitcoinExchange::closestVal(std::string const& key)
{
	std::map<std::string, float>::iterator it = this->_data_map.begin();
	while(it->first <= key)
		++it;
	--it;
	if(it != this->_data_map.end())
		return(it->second);
	return (0.0f);
}

int	BitcoinExchange::printLine(std::string line)
{
	size_t	pos = line.find("|");
	if (pos != std::string::npos)
	{
		std::string date = line.substr(0, pos);
		std::string val = line.substr(pos + 1);
		if (!checkDate(date) && getVal(val) > 0)
			std::cout << date << " => " << val << " = " << getVal(val) * closestVal(date) << std::endl;
	}
	else
		std::cerr << "Error: bad input => " << line << std::endl;
	return (0);
}

int	BitcoinExchange::display()
{
	std::string	line;
	
	if (checkFiles())
		return (1);
	if (makeDataMap())
		return (1);
	std::getline(this->_infile, line);
	if (!line.compare ("date | value"))
		std::getline(this->_infile, line);
	if (line.empty())
		return (std::cerr << "Error: Empty file" << std::endl, 1);
	while (!this->_infile.eof())
	{
		if (this->_infile.fail())
			return (this->_infile.clear(), 1);
		printLine(line);
		std::getline(this->_infile, line);
	}
	printLine(line);
	return (0);
}