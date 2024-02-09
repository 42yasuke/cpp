/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:56 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 18:20:48 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout<<"Default constructor Dog called"<<std::endl;
	this->myBrain = new Brain();
}

Dog::~Dog()
{
	std::cout<<"Destructor Dog called"<<std::endl;
	delete this->myBrain;
}

Dog::Dog(Dog const &dog) : myBrain(NULL)
{
	std::cout<<"Constructor Dog by copy called"<<std::endl;
	*this = dog;
}

Dog	&Dog::operator=(Dog const &dog)
{
	this->type = dog.type;
	if (!this->myBrain)
		this->myBrain = new Brain();
	*(this->myBrain) = *(dog.myBrain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout<<"Woooouaaf !!!"<<std::endl;
}

Brain	&Dog::getMybrain(void) const
{
	return *(this->myBrain);
}

std::ostream	&operator<<(std::ostream &os, Dog const &dog)
{
	return (os<<dog.getType()<<" "<<dog.getMybrain(), os);
}
