/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:43:53 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 15:16:51 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->setRawBits(0);
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(int const n)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->setRawBits(n << this->fract_number);
}

Fixed::Fixed(float const fl)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->setRawBits(static_cast<int>(roundf(fl * pow(2, this->fract_number))));
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

float Fixed::toFloat( void ) const
{
	return (this->_n / pow(2, this->fract_number));
}

int Fixed::toInt( void ) const
{
	return (this->_n >> this->fract_number);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &fix)
{
	os<<fix.toFloat();
	return (os);
}

bool	Fixed::operator<(Fixed const &fix)
{
	return (this->getRawBits() < fix.getRawBits());
}

bool	Fixed::operator>(Fixed const &fix)
{
	return (this->getRawBits() > fix.getRawBits());
}

bool	Fixed::operator==(Fixed const &fix)
{
	return (this->getRawBits() == fix.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fix)
{
	return (this->getRawBits() != fix.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fix)
{
	return (this->getRawBits() >= fix.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fix)
{
	return (this->getRawBits() <= fix.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fix)
{
	return (Fixed(this->getRawBits() + fix.getRawBits()));
}

Fixed	Fixed::operator-(Fixed const &fix)
{
	return (Fixed(this->getRawBits() - fix.getRawBits()));
}

Fixed	Fixed::operator/(Fixed const &fix)
{
	Fixed	res;

	if (fix.getRawBits())
		res._n = (this->getRawBits() / fix.getRawBits()) * pow(2, this->fract_number);
	return (res);
}

Fixed	Fixed::operator*(Fixed const &fix)
{
	Fixed	res;

	res._n = (this->getRawBits() * fix.getRawBits()) / pow(2, this->fract_number);
	return (res);
}

Fixed	&Fixed::operator++(void)
{
	this->_n += 1;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_n -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	(*this)._n--;
	return (tmp);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp (*this);

	(*this)._n++;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}
Fixed	const &Fixed::min(Fixed const &fix1, Fixed const &fix2)
{
	if (fix1.getRawBits() <= fix2.getRawBits())
		return (fix1);
	return (fix2);
}
Fixed	&Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}
Fixed	const &Fixed::max(Fixed const &fix1, Fixed const &fix2)
{
	if (fix1.getRawBits() >= fix2.getRawBits())
		return (fix1);
	return (fix2);
}
