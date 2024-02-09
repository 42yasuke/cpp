/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:54 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 15:20:16 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout<<"Default constructor WrongCat called"<<std::endl;
}

WrongCat::~WrongCat()
{
	std::cout<<"Destructor WrongCat called"<<std::endl;
}

WrongCat::WrongCat(WrongCat const &wcat)
{
	std::cout<<"Constructor Cat by copy called"<<std::endl;
	*this = wcat;
}

WrongCat	&WrongCat::operator=(WrongCat const &wcat)
{
	this->type = wcat.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout<<"wMiiiaou !!!"<<std::endl;
}
