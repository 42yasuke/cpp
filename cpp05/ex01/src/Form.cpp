/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:08:04 by jose              #+#    #+#             */
/*   Updated: 2024/02/15 21:52:18 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Unknown"), isSigned(false), gradeSign(MIN_GRADE), gradeExec(MIN_GRADE)
{
	std::cout << "Default constructor Form called" << std::endl;
}
Form::~Form()
{
	std::cout << "Destructor Form called" << std::endl;
}
Form::Form(std::string const &name, int gds, int gde) : name(name), isSigned(false), gradeSign(gds), gradeExec(gde)
{
	std::cout << "Constructor Form with parameter called" << std::endl;
	if (gds < MAX_GRADE || gde < MAX_GRADE)
		throw GradeTooHighException();
	if (gds > MIN_GRADE || gde > MIN_GRADE)
		throw GradeTooLowException();
}
Form::Form(Form const &f) :  name(f.name), isSigned(false), gradeSign(f.gradeSign), gradeExec(f.gradeExec)
{
	std::cout << "Constructor Form by copy called" << std::endl;
	*this = f;
}
Form	&Form::operator=(Form const &f)
{
	return (this->isSigned = f.getSigned(), *this);
}

std::string	const &Form::getName(void) const
{
	return (this->name);
}

bool	Form::getSigned(void) const
{
	return (this->isSigned);
}

int	Form::getGds(void) const
{
	return (this->gradeSign);
}

int	Form::getGde(void) const
{
	return (this->gradeExec);
}

void	Form::beSigend(Bureaucrat const &br)
{
	if (br.getGrade() > this->gradeSign)
		throw Bureaucrat::GradeTooLowException();
	br.signForm(*this);
	this->isSigned = true;
}
const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}
const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

std::ostream	&operator<<(std::ostream &os, Form const &f)
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
