/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:41:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:41:32 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain*	_brain;
	public:
	/* Default constructors */
				Cat();
				Cat(Cat const&);
	/* Default destructor */
				~Cat();
	/* Assignment	 operator */
		Cat&		operator=(Cat const&);
	/* Getter / Setter */
		std::string	getIdea(int const) const;
		void		setIdea(int const, std::string const&);
	/* Member function*/
		virtual void	makeSound() const;
};

#endif 