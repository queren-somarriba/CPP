/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:19:22 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:47:43 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    std::cout << "=== Test 1 : Création et destruction d'Animal ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j; // Doit supprimer proprement Dog + son Brain
    delete i; // Doit supprimer proprement Cat + son Brain

    std::cout << "\n=== Test 2 : Copie profonde de Dog ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "I want a bone");
    basic.setIdea(1, "I want to run");

    Dog copy = basic;
    copy.makeSound();

    std::cout << "Basic idea 0: " << basic.getIdea(0) << std::endl;
    std::cout << "Basic idea 1: " << basic.getIdea(1) << std::endl;
    std::cout << "Basic idea 2: " << basic.getIdea(2) << std::endl;
    std::cout << "Copy idea 0 : " << copy.getIdea(0) << std::endl;
    std::cout << "Copy idea 1 : " << copy.getIdea(1) << std::endl;

    // Modifier l’idée dans copy ne doit pas affecter basic
    copy.setIdea(0, "I want to sleep");

    std::cout << "After modification:" << std::endl;
    std::cout << "Basic idea 0: " << basic.getIdea(0) << std::endl;
    std::cout << "Copy idea 0 : " << copy.getIdea(0) << std::endl;

    std::cout << "\n=== Test 3 : Tableau d’animaux ===" << std::endl;
    const int size = 10;
    AAnimal* animals[size];

    for (int i = 0; i < size; ++i)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < size; ++i)
        delete animals[i];

   /* This line should cause a compilation error */
    //const AAnimal* animal = new AAnimal();

    return 0;
}