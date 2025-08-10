/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:32:06 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/06 18:29:15 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	ifs(argv[1]);
		std::string	line;
		std::string	s1(argv[2]);
		std::string	ofs_name(argv[1]);
		size_t		found;
		struct stat path_stat;

		if (s1.empty())
		{
			std::cerr << "Error: you can't remplace an empty string!" << std::endl;
			return (1);
		}
		if (ifs.fail() || !ifs.is_open())
		{
			std::cerr << "Error: opening file: " << argv[1] << std::endl;
			return (1);
		}
		if (stat(argv[1], &path_stat) != 0)
		{
			std::cerr << "Error: cannot access " << argv[1] << std::endl;
			return (1);
		}
		if (S_ISDIR(path_stat.st_mode))
		{
			std::cerr << "Error: " << argv[1] << " is a directory, not a file." << std::endl;
			return (1);
		}
		ofs_name.append(".replace");
		std::ofstream	ofs(ofs_name.c_str());
		if (ofs.fail() || !ofs.is_open())
		{
			std::cerr << "Error: opening file: " << argv[1] << ".replace" << std::endl;
			ifs.close();
			return (1);
		}
		std::getline(ifs, line);
		while (!ifs.eof())
		{
			if (ifs.fail())
			{
				ifs.clear();
				ifs.close();
				ofs.close();
				return (1);
			}
			while ((found = line.find(s1)) != std::string::npos)
			{
				line.erase(found, s1.size());
				line.insert(found, argv[3]);
			}
			ofs << line + "\n";
			std::getline(ifs, line);
		}
		ifs.close();
		ofs.close();
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return (1);
	}
	return (0);
}