/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:45:05 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/25 18:55:50 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "Creating FragTrap...\n";
    FragTrap ft("Hyperion");

    std::cout << "Calling highFivesGuys...\n";
    ft.highFivesGuys();

    std::cout << "Exiting main...\n";
    return 0;
}
