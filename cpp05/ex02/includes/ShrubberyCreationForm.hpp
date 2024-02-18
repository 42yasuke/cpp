/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:29:40 by jralph            #+#    #+#             */
/*   Updated: 2024/02/18 18:05:54 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define SHF_GDS 145
#define SHF_GDE 137
#define SHF_SUFIX "_shrubbery"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &shf);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &shf);
		virtual void	execute(Bureaucrat const &executor);
};

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &shf);

#endif