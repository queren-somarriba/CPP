/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:23:23 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:23:24 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;
	public:
		/* Default constructors */
				Dog();
				Dog(Dog const&);
		/* Default destructor */
				~Dog();
		/* Assignment operator */
		Dog&		operator=(Dog const&);
		/* Getter / Setter */
		std::string	getIdea(int const) const;
		void		setIdea(int const, std::string const&);
		/* Member function */
		virtual void	makeSound() const;
	};

#endif 