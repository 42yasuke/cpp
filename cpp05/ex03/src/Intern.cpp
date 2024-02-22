/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:50:18 by jralph            #+#    #+#             */
/*   Updated: 2024/02/22 20:48:19 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructor Intern called" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Destructor Intern called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	std::cout << "Constructor Intern by copy called" << std::endl;
	*this = other;
}

Intern	&Intern::operator=(Intern const &other)
{
	return ((void)other, *this);
}

AForm	*Intern::makePresidentialPardonForm(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyCreationForm(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string const &nameForm, std::string const &target)
{
	std::string	nameFormTab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*fctFormtab[3])(std::string const &) const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (nameForm == nameFormTab[i])
		{
			std::cout << "Intern creates Form" << std::endl;
			return (this->*(fctFormtab[i]))(target);
		}
	}
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form name not found";
}

std::ostream	&operator<<(std::ostream &os, Intern const &intern)
{
	return ((void)intern, os << "Intern at your service" << std::endl, os);
}