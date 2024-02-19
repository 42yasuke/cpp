/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/02/19 16:14:24 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testTitle(const std::string& title)
{
	std::cout << std::endl << "*** " << title << " ***" << std::endl;
}

void	testForm(const Bureaucrat& bureaucrat, AForm& form)
{
	std::cout << form;
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}


int	main(void)
{
	Bureaucrat	jose("jose", 1);
	Bureaucrat	jose42("jose42", 42);
	std::cout << jose << jose42;

	{
		testTitle("shrubbery creation");
		ShrubberyCreationForm form("home");
		testForm(jose, form);
	}
	{
		testTitle("robotomy request");
		RobotomyRequestForm form("Bender");
		testForm(jose, form);
	}
	{
		testTitle("presidential pardon");
		PresidentialPardonForm form("Macron");
		testForm(jose, form);
	}
	PresidentialPardonForm form("Macron");
	{
		testTitle("execute unsigned form");
		std::cout << form;
		jose.executeForm(form);
	}
	{
		testTitle("too low to execute");
		jose.signForm(form);
		jose42.executeForm(form);
	}
	return (0);
}
