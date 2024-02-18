/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/02/18 20:19:07 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "*** Constructor ***"<< std::endl;
	try
	{
		Bureaucrat	jose("jose", 1);
		std::cout << jose;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	jose("jose", -42);
		std::cout << jose;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl << "*** Increment ***"<< std::endl;
	try
	{
		Bureaucrat	jose("jose", 12);
		std::cout << jose;
		jose.upGrade(10);
		std::cout << jose;
		jose.upGrade();
		std::cout << jose;
		jose.upGrade(); // too high!
		std::cout << jose;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl << "*** Decrement ***"<< std::endl;
	try
	{
		Bureaucrat	jose("jose", 139);
		std::cout << jose;
		jose.downGrade(10);
		std::cout << jose;
		jose.downGrade();
		std::cout << jose;
		jose.downGrade(); // too low!
		std::cout << jose;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}