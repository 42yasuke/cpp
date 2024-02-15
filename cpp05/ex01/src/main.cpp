/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/02/15 21:55:11 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	jose("jose", 42);
	std::cout << jose;
	std::cout << "*** Constructor ***"<< std::endl;
	try
	{
		Form	formula("formula", 1000, 1);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form	formula("formula", 42, -5);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		Form	formula("formula", 10, 100);
		std::cout << formula;
		try
		{
			formula.beSigend(jose);
		}
		catch(std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		jose.upGrade(32);
		formula.beSigend(jose);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
