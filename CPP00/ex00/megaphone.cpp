/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:16:02 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/04 18:33:33 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while(*(++argv))
		{
			i = -1;
			std::string str(*argv);
			while (str[++i])
				std::cout << static_cast<char>(toupper(str[i]));
		}
		std::cout << std::endl;
	}
	return (0);
}
