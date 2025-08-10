/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:48:20 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:48:21 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
	public:
		virtual				 ~ICharacter() {}
		virtual std::string const& 	getName() const = 0;
		virtual void 			equip(AMateria* m) = 0;
		virtual void 			unequip(int idx) = 0;
		virtual void 			use(int idx, ICharacter& target) = 0;
};

#endif 