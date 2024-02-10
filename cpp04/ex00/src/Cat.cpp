/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:59 by jralph            #+#    #+#             */
/*   Updated: 2024/02/10 00:30:48 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout<<"Default constructor Cat called"<<std::endl;
}

Cat::~Cat()
{
	std::cout<<"Destructor Cat called"<<std::endl;
}

Cat::Cat(Cat const &cat) : Animal("Cat")
{
	std::cout<<"Constructor Cat by copy called"<<std::endl;
	*this = cat;
}

Cat	&Cat::operator=(Cat const &cat)
{
	this->type = cat.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout<<"Miiiaou !!!"<<std::endl;
}
