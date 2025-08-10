/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:41:37 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:41:47 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string	_type;
	public:
				AAnimal();
		virtual 	~AAnimal();
				AAnimal(AAnimal const&);
				AAnimal(std::string const&);
		AAnimal&	operator=(AAnimal const&);
		std::string	getType() const;
		void virtual	makeSound() const = 0;
};

#endif 