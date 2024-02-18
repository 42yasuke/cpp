/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:08:04 by jose              #+#    #+#             */
/*   Updated: 2024/02/18 17:13:53 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Unknown"), isSigned(false), gradeSign(MIN_GRADE), gradeExec(MIN_GRADE)
{
	std::cout << "Default constructor AForm called" << std::endl;
}
AForm::~AForm()
{
	std::cout << "Destructor AForm called" << std::endl;
}
AForm::AForm(std::string const &name, int gds, int gde) : name(name), isSigned(false), gradeSign(gds), gradeExec(gde)
{
	std::cout << "Constructor AForm with parameter called" << std::endl;
	if (gds < MAX_GRADE || gde < MAX_GRADE)
		throw GradeTooHighException();
	if (gds > MIN_GRADE || gde > MIN_GRADE)
		throw GradeTooLowException();
}
AForm::AForm(AForm const &f) :  name(f.name), isSigned(false), gradeSign(f.gradeSign), gradeExec(f.gradeExec)
{
	std::cout << "Constructor AForm by copy called" << std::endl;
	*this = f;
}
AForm	&AForm::operator=(AForm const &f)
{
	return (this->isSigned = f.getSigned(), *this);
}

std::string	const &AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getSigned(void) const
{
	return (this->isSigned);
}

int	AForm::getGds(void) const
{
	return (this->gradeSign);
}

int	AForm::getGde(void) const
{
	return (this->gradeExec);
}

void	AForm::beSigned(Bureaucrat const &br)
{
	if (br.getGrade() > this->gradeSign)
		throw Bureaucrat::GradeTooLowException();
	br.signForm(*this);
	this->isSigned = true;
}
const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}
const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

std::ostream	&operator<<(std::ostream &os, AForm const &f)
{
	os << "*** Form info ***" << std::endl;
	os << "name = " << f.getName() << ", signed = ";
	if (f.getSigned())
		os << "true";
	else
		os << "false";
	os << ", grade to sign = " << f.getGds() << ", grade to execute = " << f.getGde();
	return (os << std::endl, os);
}
