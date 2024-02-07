/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:44:14 by jralph            #+#    #+#             */
/*   Updated: 2024/02/07 20:03:32 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int	_n;
		static const int	fract_number = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &fix);
		Fixed(int const n);
		Fixed(float const fl);
		Fixed&	operator=(Fixed const &fix);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt( void ) const;
};

std::ostream&	operator<<(std::ostream &os, Fixed const &fix);

#endif