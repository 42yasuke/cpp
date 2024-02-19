/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:28:14 by jralph            #+#    #+#             */
/*   Updated: 2024/02/19 19:08:11 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &other);
		Intern	&operator=(Intern const &other);
		AForm	*makeForm(std::string const &nameForm, std::string const &target);
		AForm	*makePresidentialPardonForm(std::string const &target) const;
		AForm	*makeRobotomyRequestForm(std::string const &target) const;
		AForm	*makeShrubberyCreationForm(std::string const &target) const;

	class FormNotFoundException : public std::exception
	{
		virtual const char * what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, Intern const &intern);

#endif