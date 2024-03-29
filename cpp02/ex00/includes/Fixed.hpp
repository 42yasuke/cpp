/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:44:14 by jralph            #+#    #+#             */
/*   Updated: 2024/02/07 00:06:12 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int	_n;
		static const int	fract_number = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &fix);
		Fixed&	operator=(Fixed const &fix);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif