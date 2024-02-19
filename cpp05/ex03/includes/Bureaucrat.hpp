/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:16:04 by jose              #+#    #+#             */
/*   Updated: 2024/02/19 15:40:46 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

# define MIN_GRADE	150
# define MAX_GRADE	1

class AForm;

class Bureaucrat
{
	private:
		std::string	name;
		int		grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string const &n, int gr);
		Bureaucrat(Bureaucrat const &br);
		Bureaucrat	&operator=(Bureaucrat const &br);
		std::string	const &getName(void) const;
		int	const& getGrade(void) const;
		void	upGrade(int change=1);
		void	downGrade(int change=1);
		void	signForm(AForm &f) const;
		void	executeForm(AForm const &form) const;

		class GradeTooLowException: public std::exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &br);

#endif