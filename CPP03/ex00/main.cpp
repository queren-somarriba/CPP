/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:35:45 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 17:40:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    // Création d'un ClapTrap avec le constructeur par défaut
    ClapTrap clap1("Morty");
    
    // Utilisation du constructeur de copie
    ClapTrap clap2(clap1);

    // Affectation (test de l'opérateur =)
    ClapTrap clap3 = clap1;
    
    // Vous pouvez modifier directement le nom si l'attribut est public ou ajouter un constructeur avec nom
    ClapTrap attacker("AttackerBot");
    ClapTrap defender("DefenderBot");

    // Test des méthodes
    attacker.attack("DefenderBot");
    defender.takeDamage(3);
    defender.beRepaired(2);

    // Tester les limites d'énergie et de vie
    for (int i = 0; i < 11; ++i)
        attacker.attack("DummyTarget");

    attacker.takeDamage(15); // Devrait réduire les points de vie à 0 ou moins
    attacker.attack("AnotherBot"); // Devrait échouer
    attacker.beRepaired(5);        // Devrait échouer aussi

    return 0;
}
