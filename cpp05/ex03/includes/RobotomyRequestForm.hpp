/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:06:14 by jralph            #+#    #+#             */
/*   Updated: 2024/02/19 15:56:09 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

#define RBF_GDS 72
#define RBF_GDE 45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &shf);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &shf);
		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &shf);

#endif