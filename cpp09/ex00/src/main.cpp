/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/04/09 10:48:43 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av) 
{
	if (ac != 2)
		return (std::cout << "Error: bad usage" << std::endl, 1);
	try
	{
		BitcoinExchange bitcoinExchange;
		bitcoinExchange.ft_treatmentInputFile(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
