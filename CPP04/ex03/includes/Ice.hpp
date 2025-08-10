/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:48:21 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:48:22 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
				Ice();
				~Ice();
				Ice(Ice const& other);
		Ice&		operator=(Ice const& other);
		virtual Ice*	clone() const;
		virtual void	use(ICharacter& target);
};

#endif 