/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:37:08 by jose              #+#    #+#             */
/*   Updated: 2024/02/12 15:52:42 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout<<"Default constructor Ice called"<<std::endl;
}
Ice::~Ice()
{
	std::cout<<"Destructor Ice called"<<std::endl;
}
Ice::Ice(Ice const &ice) : AMateria("ice")
{
	std::cout<<"Constructor Ice by copy called"<<std::endl;
	*this = ice;
}
Ice	&Ice::operator=(Ice const &ice)
{
	this->_type = ice.getType();
	return (*this);
}

Ice	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}
