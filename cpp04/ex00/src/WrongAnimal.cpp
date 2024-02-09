/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:43 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 14:51:35 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknown")
{
	std::cout<<"Default constructor WrongAnimal called"<<std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"Destructor WrongAnimal called"<<std::endl;
}

WrongAnimal::WrongAnimal(std::string t) : type(t)
{
	std::cout<<"Constructor WrongAnimal with parameter "<<this->type<<" called"<<std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wanim)
{
	std::cout<<"Constructor WrongAnimal by copy called"<<std::endl;
	*this = wanim;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &wanim)
{
	this->type = wanim.type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout<<"wAAAAAAArgh !!!"<<std::endl;
}

std::ostream	&operator<<(std::ostream &os, WrongAnimal const &wanim)
{
	return (os<<wanim.getType(), os);
}
