/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:19:46 by jose              #+#    #+#             */
/*   Updated: 2024/02/19 16:35:53 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unknown"), grade(MIN_GRADE)
{
	std::cout << "Default constructor Bureaucrat called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &n, int gr) : name("Unknown"), grade(MIN_GRADE)
{
	std::cout << "Constructor Bureaucrat with parameter called" << std::endl;
	if (gr < MAX_GRADE)
		throw GradeTooHighException();
	if (gr > MIN_GRADE)
		throw GradeTooLowException();
	if (!n.empty())
		name = n;
	this->grade = gr;
}
Bureaucrat::Bureaucrat(Bureaucrat const &br) : name("Unknown"), grade(MIN_GRADE)
{
	std::cout << "Constructor Bureaucrat by copy called" << std::endl;
	*this = br;
}
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &br)
{
	this->name = br.getName();
	this->name = br.getGrade();
	return (*this);
}

std::string	const &Bureaucrat::getName(void) const
{
	return (this->name);
}

int	const &Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void	Bureaucrat::upGrade(int change)
{
	if (this->grade - change < MAX_GRADE)
		throw GradeTooHighException();
	else
		this->grade -= change;
}
void	Bureaucrat::downGrade(int change)
{
	if (this->grade + change > MIN_GRADE)
		throw GradeTooLowException();
	else
		this->grade += change;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low!";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high!";
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &br)
{
	os << "***** Bureaucrat info *****" << std::endl;
	os << "name = " << br.getName() << ", grade = " << br.getGrade() << std::endl;
	return (os);
}
