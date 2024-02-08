/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:30:34 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 19:37:05 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout<<"Default constructor ScavTrap called"<<std::endl;
	this->Name = std::string("Unknown");
	this->Energy = 50;
	this->Hit = 100;
	this->Attack = 20;
	this->MaxHit = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"Destructo ScavTrap called"<<std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
	std::cout<<"Constructor ScavTrap with parameter called"<<std::endl;
	this->Energy = 50;
	this->Hit = 100;
	this->MaxHit = 100;
	this->Attack = 20;
}

ScavTrap::ScavTrap(ScavTrap const &scav)
{
	std::cout<<"Constructor ScavTrap copy by assignement called"<<std::endl;
	*this = scav;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &scav)
{
	this->Name = scav.Name;
	this->Attack = scav.Attack;
	this->Energy = scav.Energy;
	this->Hit = scav.Hit;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->Hit)
	{
		if (this->Energy)
		{
			std::cout<<"ScavTrap "<<this->Name<<" attacks "<<target<<", causing "<<this->Attack<<" points of damage!"<<std::endl;
			if (this->Energy)
				this->Energy--;
		}
		else
			std::cout<<"ScavTrap "<<this->Name<<" cannot attack (no more energy)"<<std::endl;
	}
	else
		std::cout<<"ScavTrap "<<this->Name<<" cannot attack (he is dead)"<<std::endl;
}

std::ostream	&operator<<(std::ostream &os, ScavTrap const &scav)
{
	std::cout<<"***** ScavTrap Info *****"<<std::endl;
	std::cout<<"name: "<<scav.ft_getName()<<std::endl;
	std::cout<<"energy: "<<scav.ft_getEnergy()<<std::endl;
	std::cout<<"attack: "<<scav.ft_getAttack()<<std::endl;
	std::cout<<"Hit: "<<scav.ft_getHit()<<std::endl;
	std::cout<<"*************************"<<std::endl;
	return (os);
}

void	ScavTrap::guardGate(void)
{
	std::cout<<"ScavTrap "<<this->Name<<" is now in Gate keeper mode"<<std::endl;
}
