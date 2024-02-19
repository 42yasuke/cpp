/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:09:01 by jralph            #+#    #+#             */
/*   Updated: 2024/02/19 15:55:24 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Unknown", RBF_GDS, RBF_GDE)
{
	std::cout << "Default constructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, RBF_GDS, RBF_GDE)
{
	std::cout << "Constructor RobotomyRequestForm with parameter "<< target << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rbf) : AForm(rbf.getName(), RBF_GDS, RBF_GDE)
{
	std::cout << "Constructor RobotomyRequestForm by copy called" << std::endl;
	*this = rbf;
}
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rbf)
{
	return (this->isSigned = rbf.getSigned(), *this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->gradeExec)
		throw GradeTooLowException();
	if (!this->isSigned)
		throw UnSignedException();
	std::cout << "* LOUD DRILLING NOISES *" << std::endl << executor.getName();
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << " has been successfully robotimized!" << std::endl;
	else
		std::cout << " had some problems and its robotomy failed!" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &rbf)
{
	os << "*** RobotomyRequestForm info ***" << std::endl;
	os << "name = " << rbf.getName() << ", signed = ";
	if (rbf.getSigned())
		os << "true";
	else
		os << "false";
	os << ", grade to sign = " << rbf.getGds() << ", grade to execute = " << rbf.getGde();
	return (os << std::endl, os);
}
