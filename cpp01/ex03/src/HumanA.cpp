/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:20:51 by jose              #+#    #+#             */
/*   Updated: 2024/02/02 16:51:26 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &w) : name(n), arme(w)
{
}
HumanA::~HumanA()
{
	std::cout << "humanA " << this->name << " is destroyed" << std::endl;
}
void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->arme.getType() << std::endl;
}
