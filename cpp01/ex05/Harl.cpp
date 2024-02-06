/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:14:03 by jose              #+#    #+#             */
/*   Updated: 2024/02/06 11:22:08 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "***** DEBUG MESSAGE *****" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "***** INFO MESSAGE *****" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "***** WARNING MESSAGE *****" << std::endl;
}
void	Harl::error(void)
{
	std::cout << "***** ERROR MESSAGE *****" << std::endl;
}

void	Harl::complain(std::string level)
{
	void	*(Harl::f[4])(void) = {&debug, &info, &warning, &error};
	for (int i = 0; i < level.size(); i++)
		f[i]();
}
