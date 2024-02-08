/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:54:49 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 20:03:19 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout<<"Default constructor FragTrap called"<<std::endl;
	this->Name = std::string("Unknown");
	this->Energy = 100;
	this->Hit = 100;
	this->Attack = 30;
	this->MaxHit = 100;
}

FragTrap::~FragTrap()
{
	std::cout<<"Destructo FragTrap called"<<std::endl;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
	std::cout<<"Constructor FragTrap with parameter called"<<std::endl;
	this->Energy = 100;
	this->Hit = 100;
	this->MaxHit = 100;
	this->Attack = 30;
}

FragTrap::FragTrap(FragTrap const &frag)
{
	std::cout<<"Constructor FragTrap copy by assignement called"<<std::endl;
	*this = frag;
}

FragTrap	&FragTrap::operator=(FragTrap const &frag)
{
	this->Name = frag.Name;
	this->Attack = frag.Attack;
	this->Energy = frag.Energy;
	this->Hit = frag.Hit;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->Hit)
	{
		if (this->Energy)
		{
			std::cout<<"FragTrap "<<this->Name<<" attacks "<<target<<", causing "<<this->Attack<<" points of damage!"<<std::endl;
			if (this->Energy)
				this->Energy--;
		}
		else
			std::cout<<"FragTrap "<<this->Name<<" cannot attack (no more energy)"<<std::endl;
	}
	else
		std::cout<<"FragTrap "<<this->Name<<" cannot attack (he is dead)"<<std::endl;
}

std::ostream	&operator<<(std::ostream &os, FragTrap const &frag)
{
	std::cout<<"***** FragTrap Info *****"<<std::endl;
	std::cout<<"name: "<<frag.ft_getName()<<std::endl;
	std::cout<<"energy: "<<frag.ft_getEnergy()<<std::endl;
	std::cout<<"attack: "<<frag.ft_getAttack()<<std::endl;
	std::cout<<"Hit: "<<frag.ft_getHit()<<std::endl;
	std::cout<<"*************************"<<std::endl;
	return (os);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout<<"FragTrap "<<this->Name<<" asks a positive high fives"<<std::endl;
}
