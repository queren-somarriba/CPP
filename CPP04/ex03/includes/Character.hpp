/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:48:23 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:48:24 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria*		_inventory[4];
		std::string		_name;
	public:
		/* Constructors */
					Character();
					Character(std::string const&);
					Character(Character const&);
		/* Destructor */
					 ~Character();
		/* Overload Operation = */
		Character&		operator=(Character const&);
		/* Member functions */
		std::string const& 	getName() const;
		void			equip(AMateria* m);
		void			unequip(int idx);
		virtual void		use(int idx, ICharacter& target);
};

#endif 