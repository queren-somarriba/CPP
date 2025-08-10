/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:20:43 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:28:26 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string	_type;
	public:
				Animal();
		virtual 	~Animal();
				Animal(Animal const&);
				Animal(std::string const&);
		Animal&		operator=(Animal const&);
		std::string	getType() const;
		void virtual	makeSound() const;
};

#endif 