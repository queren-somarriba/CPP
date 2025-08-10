/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:07:33 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/23 17:30:40 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
    // Test case: Valid Bureaucrat creation and grade manipulation
    try 
    {
        Bureaucrat bureaucrat("Mike", 100);
        std::cout << bureaucrat << std::endl;
        bureaucrat.increment();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrement();
        std::cout << bureaucrat << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // Attempt to create a Bureaucrat with an invalid grade (should throw an exception)
    try 
    {
        Bureaucrat invalidBureaucrat("Invalid Test", 151); 
    }
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat zeroGrade("Zero Grade", 0); 
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat negativeGrade("Negative Grade", -10); 
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    
    // Test case: Incrementing grade beyond the upper limit (1 is the highest grade)
    try 
    {
        Bureaucrat highEdgeCase("High Edge Case", 1);
        std::cout << std::endl << highEdgeCase << std::endl;
        highEdgeCase.increment();
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    // Test case: Decrementing grade beyond the lower limit (150 is the lowest grade)
    try 
    {
        Bureaucrat lowEdgeCase("Low Edge Case", 150);
        std::cout << std::endl << lowEdgeCase << std::endl;
        lowEdgeCase.decrement();
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
}