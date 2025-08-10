/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:08 by qsomarri          #+#    #+#             */
/*   Updated: 2025/06/11 18:09:07 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int			_value;
		static int const	_bits_nb;
	public:
					Fixed(void);
					Fixed(Fixed const & f);
					Fixed(int const interger);
					Fixed(float const nb);
					~Fixed(void);
		Fixed & 		operator=(Fixed const & f);

		int			getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int			toInt(void) const;
};

std::ostream&		operator<<(std::ostream& ofs, Fixed const& f);

#endif 