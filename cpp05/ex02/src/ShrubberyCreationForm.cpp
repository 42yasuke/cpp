/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:31:20 by jralph            #+#    #+#             */
/*   Updated: 2024/02/18 20:40:09 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unknown", SHF_GDS, SHF_GDE)
{
	std::cout << "Default constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, SHF_GDS, SHF_GDE)
{
	std::cout << "Constructor ShrubberyCreationForm with parameter "<< target << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shf) : AForm(shf.getName(), SHF_GDS, SHF_GDE)
{
	std::cout << "Constructor ShrubberyCreationForm by copy called" << std::endl;
	*this = shf;
}
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shf)
{
	return (this->isSigned = shf.getSigned(), *this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (this->gradeExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (this->isSigned)
	{
		executor.executeForm(*this);
		std::string	file_name = this->getName() + SHF_SUFIX;
		std::ofstream	outfile(file_name.c_str());
		if (outfile)
		{
			outfile
			<< "               ,@@@@@@@," << std::endl
			<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
			<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
			<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
			<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
			<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
			<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
			<< "       |o|        | |         | |" << std::endl
			<< "       |.|        | |         | |" << std::endl
			<< "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		}
		else
			std::cout << "Outfile open failled" << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &shf)
{
	os << "*** ShrubberyCreationForm info ***" << std::endl;
	os << "name = " << shf.getName() << ", signed = ";
	if (shf.getSigned())
		os << "true";
	else
		os << "false";
	os << ", grade to sign = " << shf.getGds() << ", grade to execute = " << shf.getGde();
	return (os << std::endl, os);
}
