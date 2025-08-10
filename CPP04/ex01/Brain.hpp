/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:23:29 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:23:38 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		/* Default constructors */
				Brain();
				Brain(Brain const&);
		/* Default destructor */
				~Brain();
		/* Assignment operator */
		Brain&		operator=(Brain const&);
		/* Getter / Setter */
		std::string	getIdea(int const) const;
		void		setIdea(int const, std::string const&);
		/* Member attribute */
		std::string	ideas[100];
};

#endif 