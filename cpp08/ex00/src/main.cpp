/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/03/04 21:25:29 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Value found at index: " << std::distance(vec.begin(), it) << std::endl;
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6); // Valeur non présente dans le vecteur
		std::cout << "Value found at index: " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
