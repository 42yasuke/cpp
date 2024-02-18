/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:24:14 by jralph            #+#    #+#             */
/*   Updated: 2024/02/18 21:38:40 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Unknown", PPF_GDS, PPF_GDE)
{
	std::cout << "Default constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, PPF_GDS, PPF_GDE)
{
	std::cout << "Constructor PresidentialPardonForm with parameter "<< target << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ppf) : AForm(ppf.getName(), PPF_GDS, PPF_GDE)
{
	std::cout << "Constructor PresidentialPardonForm by copy called" << std::endl;
	*this = ppf;
}
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &ppf)
{
	return (this->isSigned = ppf.getSigned(), *this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	if (this->gradeExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->isSigned)
	{
		executor.executeForm(*this);
		std::cout << executor.getName() <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
		std::cout << executor.getName() <<" cannot be pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, PresidentialPardonForm const &ppf)
{
	os << "*** PresidentialPardonForm info ***" << std::endl;
	os << "name = " << ppf.getName() << ", signed = ";
	if (ppf.getSigned())
		os << "true";
	else
		os << "false";
	os << ", grade to sign = " << ppf.getGds() << ", grade to execute = " << ppf.getGde();
	return (os << std::endl, os);
}
