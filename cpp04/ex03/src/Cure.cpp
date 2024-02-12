/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:32:43 by jose              #+#    #+#             */
/*   Updated: 2024/02/12 15:52:57 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout<<"Default constructor Cure called"<<std::endl;
}
Cure::~Cure()
{
	std::cout<<"Destructor Cure called"<<std::endl;
}
Cure::Cure(Cure const &cure) : AMateria("cure")
{
	std::cout<<"Constructor Cure by copy called"<<std::endl;
	*this = cure;
}
Cure	&Cure::operator=(Cure const &cure)
{
	this->_type = cure.getType();
	return (*this);
}

Cure	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout<<"* heals "<<target.getName()<<"’s wounds * "<<std::endl;
}
