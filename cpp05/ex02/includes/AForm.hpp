/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:59:27 by jose              #+#    #+#             */
/*   Updated: 2024/02/18 18:05:47 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string	const name;
		bool	isSigned;
		int	const gradeSign;
		int	const gradeExec;
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string const &name, int gds, int gde);
		AForm(AForm const &f);
		AForm	&operator=(AForm const &f);
		std::string	const &getName(void) const;
		bool	getSigned(void) const;
		int	getGds(void) const;
		int	getGde(void) const;
		void	beSigned(Bureaucrat const &br);
		virtual void	execute(Bureaucrat const & executor) = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, AForm const &f);

#endif