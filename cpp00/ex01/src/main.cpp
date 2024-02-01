/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:14:29 by jose              #+#    #+#             */
/*   Updated: 2024/02/01 00:26:51 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string ft_choose_between(void)
{
	std::string choice;
	std::cout << "choose between ADD, SEARCH or QUIT" << std::endl;
	std::getline(std::cin, choice);
	while (choice != "ADD" && choice != "SEARCH" && choice != "QUIT")
		std::getline(std::cin, choice);
	return (choice);
}

int	main(void)
{
	PhoneBook	phone;

	std::string choice;
	while (true)
	{
		std::cout << std::endl << "********** MY PHONE BOOK **********" << std::endl;
		choice = ft_choose_between();
		if (choice == "ADD")
		{
			std::cout << "********* creating a new contact **********" << std::endl;
			phone.ft_add_contact();
		}
		else if (choice == "SEARCH")
			phone.ft_search_contact();
		else
			break ;
	}
	return (EXIT_SUCCESS);
}
