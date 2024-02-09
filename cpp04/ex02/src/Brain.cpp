/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:54:34 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 18:08:52 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Default constructor Brain called"<<std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Idea";
}
Brain::~Brain()
{
	std::cout<<"Destructor Brain called"<<std::endl;
	delete[] this->ideas;
}
Brain::Brain(Brain const &br)
{
	std::cout<<"Constructor Brain by copy called"<<std::endl;
	*this = br;
}

Brain	&Brain::operator=(Brain const &br)
{
	std::cout<<"Ideas stollen form an other Brain"<<std::endl;
	delete[] this->ideas;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = br.getIdeas()[i];
	return (*this);
}

std::string	*Brain::getIdeas(void) const
{
	return (this->ideas);
}

std::ostream	&operator<<(std::ostream &os, Brain const &br)
{
	return (std::cout<<"has a Brain with 100 ideas at the adress : "<<br.getIdeas()<<std::endl, os);
}
