/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:22:27 by jose              #+#    #+#             */
/*   Updated: 2024/02/01 13:46:22 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::ft_set_name(std::string name)
{
	this->_name = name;
}
