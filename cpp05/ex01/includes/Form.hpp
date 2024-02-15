/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:59:27 by jose              #+#    #+#             */
/*   Updated: 2024/02/15 21:46:12 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	const name;
		bool	isSigned;
		int	const gradeSign;
		int	const gradeExec;
	public:
		Form();
		~Form();
		Form(std::string const &name, int gds, int gde);
		Form(Form const &f);
		Form	&operator=(Form const &f);
		std::string	const &getName(void) const;
		bool	getSigned(void) const;
		int	getGds(void) const;
		int	getGde(void) const;
		void	beSigend(Bureaucrat const &br);

		class GradeTooHighException : public std::exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Form const &f);

#endif