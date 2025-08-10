/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:41:19 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/10 19:41:22 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string	_type;
		public:
				WrongAnimal();
		virtual		~WrongAnimal();
				WrongAnimal(WrongAnimal const&);
				WrongAnimal(std::string const&);
		WrongAnimal&	operator=(WrongAnimal const&);
		std::string	getType() const;
		void virtual	makeSound() const;
};

#endif 