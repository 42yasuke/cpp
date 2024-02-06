/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:14:03 by jose              #+#    #+#             */
/*   Updated: 2024/02/06 14:15:56 by jralph           ###   ########.fr       */
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
	void	(Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < (int)level.size(); i++)
		(this->*f[i])();
}
