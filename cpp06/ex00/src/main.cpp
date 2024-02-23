/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/02/23 18:56:07 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2 || !strlen(av[1]))
		return (std::cout << "Error: wrong number of parameters" << std::endl, 1);
	try
	{
		ScalarConverter::convert(std::string(av[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error:" << e.what() << std::endl;
	}
	
	return (0);
}