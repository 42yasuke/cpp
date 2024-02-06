/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:14:00 by jose              #+#    #+#             */
/*   Updated: 2024/02/06 11:27:00 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout<<"error : wrong number of parameters"<<std::endl;
		return 1;
	}
	std::string	arg = std::string();
	for (size_t i = 0; av[1][i]; i++)
		arg+=av[1][i];
	std::string	harl_tab[4] = {"DEBUG", "INFO", "WARING", "ERROR"};
	int	i = -1;
	while (++i < 4 && arg != harl_tab[i]);
	if (i == 4)
	{
		std::cout<<"error : wrong parameter"<<std::endl;
		std::cout<<"Harl only accept those parameters : DEBUG INFO WARING ERROR"<<std::endl;
		return 1;
	}
	std::string	level = std::string();
	for (int j = 0; j < i + 1; j++)
		level+= 'a';
	Harl	harl = Harl();
	return (harl.complain(level), 0);
}
