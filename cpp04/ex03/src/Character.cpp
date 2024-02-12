/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:52:15 by jose              #+#    #+#             */
/*   Updated: 2024/02/12 11:51:05 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Unkwnon")
{
	std::cout<<"Default constructor Character called"<<std::endl;
	for (int i = 0; i < 4; i++)
		this->materials[i] = NULL;
}
Character::~Character()
{
	std::cout<<"Destructor Character called"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i])
			delete this->materials[i];
	}
}
Character::Character(Character const &charac)
{
	std::cout<<"Constructor Character by copy called"<<std::endl;
	*this = charac;
}
Character	&Character::operator=(Character const &charac)
{
	this->name = charac.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i])
			delete this->materials[i];
		if (charac.materials[i])
			this->materials[i] = charac.materials[i].clone();
		else
			this->materials[i] = NULL;
	}
	return (*this);
}

std::string	const &Character::getName() const
{
	return (this->name);
}

std::string	const Character::getTypeM(int idx) const
{
	if (this->materials[idx])
		return (this->materials[idx].getType());
	return ("empty");
}

void	Character::equip(AMateria* m)
{
	int	i = -1;
	while (++i < 4 && this->materials[i]);
	if (i == 4)
		std::cout<<"Character "<<this->getName()<<" cannot equip more Materia (epuipement already full)"<<std::endl;
	else
	{
		this->materials[i] = m;
		std::cout<<"Character "<<this->getName()<<" equiped a new Materia "<<m->getType()<<std::endl;
	}
}
void	Character::unequip(int idx)
{
	if (this->materials[idx])
	{
		std::cout<<"Character "<<this->getName()<<" drop a Mataria "<<this->materials[idx]->getType()<<std::endl;
		this->materials[idx] = NULL;
	}
	else
		std::cout<<"Character "<<this->getName()<<" cannot unquip (emplacement empty)"<<std::endl;
}
void	Character::use(int idx, ICharacter& target)
{
	if (this->materials[idx])
		this->materials[idx].use(target);
	else
		std::cout<<"Character "<<this->getName()<<" cannot use it (emplacement empty)"<<std::endl;
}

std::ostream 	&operator<<(std::ostream &os, Character const &charac)
{
	os<<charac.getName()<<" [ ";
	for (int i = 0; i < 4; i++)
		os<<charac.getTypeM(i)<<" ";
	return (os<<"]", os);
}
