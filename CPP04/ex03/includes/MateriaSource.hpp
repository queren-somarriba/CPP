/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:48:18 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:48:19 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_array[4];
	public:
				MateriaSource();
				MateriaSource(MateriaSource const&);
				~MateriaSource();
		MateriaSource&	operator=(MateriaSource const&);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif 