/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:37:08 by jose              #+#    #+#             */
/*   Updated: 2024/02/10 02:00:10 by jose             ###   ########.fr       */
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
}

Ice	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout<<"* shoots an ice bolt at "<<static_cast<Character>(target).getName()<<" *"<<std::endl;
}
