/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:48:22 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:48:23 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
				Cure();
				~Cure();
				Cure(Cure const& other);
		Cure&		operator=(Cure const& other);
		virtual Cure*	clone() const;
		virtual void	use(ICharacter& target);
};

#endif 