/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/02/19 20:00:45 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	testMake(const std::string& formName, const std::string& target)
{
	std::cout << std::endl << std::endl << "*** " << formName << " ***" << std::endl;
	Bureaucrat	jose("jose", 42);
	Intern		intern;
	AForm* form = intern.makeForm(formName, target);
	std::cout << *form;
	jose.signForm(*form);
	jose.executeForm(*form);
	delete form;
}

int	main()
{
	try
	{
		testMake("robotomy request", "Bender");
		testMake("presidential pardon", "Macron");
		testMake("shrubbery creation", "home");
		testMake("not a form", "you");
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}