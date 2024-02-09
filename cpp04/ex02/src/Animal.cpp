/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:02 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 19:28:13 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout<<"Default constructor Animal called"<<std::endl;
}

Animal::~Animal()
{
	std::cout<<"Destructor Animal called"<<std::endl;
}

Animal::Animal(std::string t) : type(t)
{
	std::cout<<"Constructor Animal with parameter "<<this->type<<" called"<<std::endl;
}

Animal::Animal(Animal const &anim)
{
	std::cout<<"Constructor Animal by copy called"<<std::endl;
	*this = anim;
}

Animal	&Animal::operator=(Animal const &anim)
{
	this->type = anim.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout<<"AAAAAAArgh !!!"<<std::endl;
}

std::ostream	&operator<<(std::ostream &os, Animal const &anim)
{
	return (os<<anim.getType(), os);
}
