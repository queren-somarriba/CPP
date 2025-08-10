/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:29:17 by qsomarri          #+#    #+#             */
/*   Updated: 2025/05/23 15:29:18 by qsomarri         ###   ########.fr       */
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
	~Fixed(void);
	Fixed & operator=(Fixed const & f);

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif 