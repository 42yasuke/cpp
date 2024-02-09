/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:56 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 15:19:56 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout<<"Default constructor Dog called"<<std::endl;
}

Dog::~Dog()
{
	std::cout<<"Destructor Dog called"<<std::endl;
}

Dog::Dog(Dog const &dog)
{
	std::cout<<"Constructor Dog by copy called"<<std::endl;
	*this = dog;
}

Dog	&Dog::operator=(Dog const &dog)
{
	this->type = dog.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout<<"Woooouaaf !!!"<<std::endl;
}
