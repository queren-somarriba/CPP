/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:59:13 by qsomarri          #+#    #+#             */
/*   Updated: 2025/07/19 13:16:15 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"

int main()
{
    srand(time(0));
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "\n--- Test #" << (i + 1) << " ---" << std::endl;
        Base* p = generate();
        if (p)
        {
            std::cout << "Identify by pointer:   ";
            identify(p);
            std::cout << "Identify by reference: ";
            identify(*p);
            delete p;
            p = 0;
        }
    }
    return (0);
}

