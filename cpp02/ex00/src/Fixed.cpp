/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:43:53 by jralph            #+#    #+#             */
/*   Updated: 2024/02/07 00:06:35 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_n = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(Fixed const &fix)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = fix;
}

Fixed	&Fixed::operator=(Fixed const &fix)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->setRawBits(fix.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}
