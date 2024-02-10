/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:59 by jralph            #+#    #+#             */
/*   Updated: 2024/02/10 00:32:58 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout<<"Default constructor Cat called"<<std::endl;
	this->myBrain = new Brain();
}

Cat::~Cat()
{
	std::cout<<"Destructor Cat called"<<std::endl;
	delete this->myBrain;
}

Cat::Cat(Cat const &cat) : Animal("Cat"), myBrain(NULL)
{
	std::cout<<"Constructor Cat by copy called"<<std::endl;
	*this = cat;
}

Cat	&Cat::operator=(Cat const &cat)
{
	this->type = cat.type;
	if (!this->myBrain)
		this->myBrain = new Brain();
	*(this->myBrain) = *(cat.myBrain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout<<"Miiiaou !!!"<<std::endl;
}

Brain	&Cat::getMybrain(void) const
{
	return *(this->myBrain);
}

std::ostream	&operator<<(std::ostream &os, Cat const &cat)
{
	return (os<<cat.getType()<<" "<<cat.getMybrain(), os);
}
