/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:11:29 by jose              #+#    #+#             */
/*   Updated: 2024/02/12 14:56:53 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#include "Character.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public :
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria(AMateria const &am);
		AMateria	&operator=(AMateria const &am);
		std::string	const &getType() const; // Returns the materia type
		virtual AMateria	*clone(void) const = 0;
		virtual void	use(ICharacter &target);
};

std::ostream	&operator<<(std::ostream &os, AMateria const &am);

#endif