/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:44:14 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 14:35:11 by jralph           ###   ########.fr       */
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
		bool	operator<(Fixed const &fix);
		bool	operator>(Fixed const &fix);
		bool	operator<=(Fixed const &fix);
		bool	operator>=(Fixed const &fix);
		bool	operator==(Fixed const &fix);
		bool	operator!=(Fixed const &fix);
		Fixed	operator+(Fixed const &fixe);
		Fixed	operator-(Fixed const &fixe);
		Fixed	operator*(Fixed const &fixe);
		Fixed	operator/(Fixed const &fixe);
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator--(int);
		Fixed	operator++(int);
		static Fixed	&min(Fixed &fix1, Fixed &fix2);
		static Fixed	const &min(Fixed const &fix1, Fixed const &fix2);
		static Fixed	&max(Fixed &fix1, Fixed &fix2);
		static Fixed	const &max(Fixed const &fix1, Fixed const &fix2);
};

std::ostream&	operator<<(std::ostream &os, Fixed const &fix);

#endif