/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:03:39 by jose              #+#    #+#             */
/*   Updated: 2024/02/10 00:59:19 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout<<"Constructor AMateria called with parameter "<<type<<std::endl;
}
AMateria::~AMateria()
{
	std::cout<<"Destructor AMateria called"<<std::endl;
}
AMateria::AMateria(AMateria const &am)
{
	std::cout<<"Constructor AMateria cpopy called"<<std::endl;
	*this = am;
}
AMateria	&AMateria::operator=(AMateria const &am)
{
	this->_type = am._type;
}

std::string	const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}

std::ostream	&operator<<(std::ostream &os, AMateria const &am)
{
	return (os<<am.getType(), os);
}
