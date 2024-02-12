/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:03:46 by jose              #+#    #+#             */
/*   Updated: 2024/02/12 11:53:25 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout<<"Default constructor MateriaSource called"
	for (int i = 0; i < 4; i++)
		this->materials[i] = NULL;
}
MateriaSource::~MateriaSource()
{
	std::cout<<"Destructor MateriaSouce called"<<std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i])
			delete this->materials[i];
	}
}
MateriaSource::MateriaSource(MateriaSource const &mat)
{
	std::cout<<"Constructor Character by copy called"<<std::endl;
	*this = mat;
}
MateriaSource	&MateriaSource::operator=(MateriaSource const &mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i])
			delete this->materials[i];
		if (mat.materials[i])
			this->materials[i] = charac.materials[i].clone();
		else
			this->materials[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i = -1;
	while (++i < 4 && this->materials[i]);
	if (i == 4)
		std::cout<<"Cannot learn more Materia (already full)"<<std::endl;
	else
	{
		this->materials[i] = this->createMateria(m->getType());
		if (this->materials[i])
			std::cout<<"Learned a new Materia "<<m->getType()<<std::endl;
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	return (NULL);
}

std::string	const MateriaSource::getTypeM(int idx) const
{
	if (this->materials[idx])
		return (this->materials[idx].getType());
	return ("empty");
}

std::ostream	&operator<<(std::ostream &os, MateriaSource const &mat)
{
	os<<"MateriaSource"<<" [ ";
	for (int i = 0; i < 4; i++)
		os<<mat.getTypeM(i)<<" ";
	return (os<<"]", os);
}
