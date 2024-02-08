/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:52:35 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 19:36:31 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout<<"Default constructor ClapTrap called"<<std::endl;
	this->Name = std::string("Unknown");
	this->Energy = 10;
	this->Hit = 10;
	this->Attack = 0;
	this->MaxHit = 10;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"Destructor ClapTrap called"<<std::endl;
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout<<"Constructor ClapTrap with parameter called"<<std::endl;
	this->Name = n;
	this->Energy = 10;
	this->Hit = 10;
	this->Attack = 0;
	this->MaxHit = 10;
}

ClapTrap::ClapTrap(ClapTrap const &clap)
{
	std::cout<<"Constructor ClapTrap copy by assignement called"<<std::endl;
	*this = clap;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &clap)
{
	this->Name = clap.Name;
	this->Attack = clap.Attack;
	this->Energy = clap.Energy;
	this->Hit = clap.Hit;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->Hit)
	{
		if (this->Energy)
		{
			std::cout<<"ClapTrap "<<this->Name<<" attacks "<<target<<", causing "<<this->Attack<<" points of damage!"<<std::endl;
			if (this->Energy)
				this->Energy--;
		}
		else
			std::cout<<"ClapTrap "<<this->Name<<" cannot attack (no more energy)"<<std::endl;
	}
	else
		std::cout<<"ClapTrap "<<this->Name<<" cannot attack (he is dead)"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->Hit-=amount;
	if (this->Hit < 0)
		this->Hit = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit)
	{
		if (this->Energy)
		{
			std::cout<<"ClapTrap "<<this->Name<<" repairs itself with "<<amount<<" points of health!"<<std::endl;
			this->Hit+=amount;
			if (this->Hit > this->MaxHit)
				this->Hit = this->MaxHit;
			if (this->Energy)
				this->Energy--;
		}
		else
			std::cout<<"ClapTrap "<<this->Name<<" cannot repairs itself (no more energy)"<<std::endl;
	}
	else
		std::cout<<"ClapTrap "<<this->Name<<" cannot repairs itself (he is dead)"<<std::endl;
}

std::string	ClapTrap::ft_getName(void) const
{
	return (this->Name);
}

int	ClapTrap::ft_getEnergy(void) const
{
	return (this->Energy);
}
int	ClapTrap::ft_getAttack(void) const
{
	return (this->Attack);
}
int	ClapTrap::ft_getHit(void) const
{
	return (this->Hit);
}

std::ostream	&operator<<(std::ostream &os, ClapTrap const &clap)
{
	std::cout<<"***** ClapTrap Info *****"<<std::endl;
	std::cout<<"name: "<<clap.ft_getName()<<std::endl;
	std::cout<<"energy: "<<clap.ft_getEnergy()<<std::endl;
	std::cout<<"attack: "<<clap.ft_getAttack()<<std::endl;
	std::cout<<"Hit: "<<clap.ft_getHit()<<std::endl;
	std::cout<<"*************************"<<std::endl;
	return (os);
}
