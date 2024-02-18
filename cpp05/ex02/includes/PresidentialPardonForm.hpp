/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:22:29 by jralph            #+#    #+#             */
/*   Updated: 2024/02/18 19:26:29 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTPARDINFORM_HPP
#define PRESIDENTPARDINFORM_HPP

#include "AForm.hpp"

#define PPF_GDS 25
#define PPF_GDE 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &ppf);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &ppf);
		virtual void	execute(Bureaucrat const &executor);
};

std::ostream	&operator<<(std::ostream &os, PresidentialPardonForm const &ppf);

#endif