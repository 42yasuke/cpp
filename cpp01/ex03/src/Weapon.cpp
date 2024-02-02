/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:20:29 by jose              #+#    #+#             */
/*   Updated: 2024/02/02 17:02:37 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string n)
{
	this->type = n;
}
Weapon::~Weapon()
{
	std::cout << "weapon " << this->type << " destroyed" << std::endl;
}
std::string const&	Weapon::getType(void)
{
	return (this->type);
}
void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
