/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:21:06 by jose              #+#    #+#             */
/*   Updated: 2024/02/02 16:58:16 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
	this->name = n;
	this->arme = NULL;
}
HumanB::~HumanB()
{
	std::cout << "humanB " << this->name << " is destroyed" << std::endl;
}
void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->arme->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &club)
{
	this->arme = &club;
}
