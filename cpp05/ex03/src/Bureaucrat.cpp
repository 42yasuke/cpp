/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:19:46 by jose              #+#    #+#             */
/*   Updated: 2024/02/19 16:08:43 by jralph           ###   ########.fr       */
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

Bureaucrat::Bureaucrat(std::string const &n, int gr) : name(n), grade(MIN_GRADE)
{
	std::cout << "Constructor Bureaucrat with parameter called" << std::endl;
	if (gr < MAX_GRADE)
		throw GradeTooHighException();
	if (gr > MIN_GRADE)
		throw GradeTooLowException();
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
	this->grade -= change;
}
void	Bureaucrat::downGrade(int change)
{
	if (this->grade + change > MIN_GRADE)
		throw GradeTooLowException();
	this->grade += change;
}

void	Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << ", signed Form " << f.getName()<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat " << this->getName() << ", couldn’t sign Form" << f.getName()
		<< " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low!";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high!";
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << this->name << " executed Form " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat " << this->getName() << ", cannot execute Form" << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &br)
{
	os << "***** Bureaucrat info *****" << std::endl;
	os << "name = " << br.getName() << ", grade = " << br.getGrade() << std::endl;
	return (os);
}
