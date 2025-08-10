/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:31:35 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 17:45:31 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp" // Assure-toi que le nom du fichier et de la classe est corrigé

int main()
{
    std::cout << "=== Tests ClapTrap ===" << std::endl;

    ClapTrap clap1("Morty");
    ClapTrap clap2(clap1);              // Test constructeur de copie
    ClapTrap clap3 = clap1;             // Test opérateur d'affectation

    ClapTrap attacker("AttackerBot");
    ClapTrap defender("DefenderBot");

    attacker.attack("DefenderBot");
    defender.takeDamage(3);
    defender.beRepaired(2);

    for (int i = 0; i < 11; ++i)
        attacker.attack("DummyTarget");

    attacker.takeDamage(15);
    attacker.attack("AnotherBot"); // Échec attendu
    attacker.beRepaired(5);        // Échec attendu

    std::cout << "\n=== Tests ScavTrap ===" << std::endl;

    ScavTrap scav1("Rick");
    ScavTrap scav2(scav1);               // Test constructeur de copie
    ScavTrap scav3 = scav1;              // Test opérateur d'affectation

    scav1.attack("Jerry");              // Test méthode override
    scav1.takeDamage(30);
    scav1.beRepaired(10);
    scav1.guardGate();                  // Test de la méthode spéciale

    // Test limites énergie/vie
    for (int i = 0; i < 51; ++i)
        scav1.attack("Target");

    scav1.takeDamage(200);              // Vie tombe à 0
    scav1.attack("Anyone");             // Échec attendu
    scav1.guardGate();                  // Toujours autorisé

    std::cout << "=== Fin des tests ===" << std::endl;

    return 0;
}