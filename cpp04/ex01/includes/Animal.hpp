/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:02 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 15:57:15 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal(std::string t);
		Animal(Animal const &anim);
		Animal	&operator=(Animal const &anim);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
};

std::ostream	&operator<<(std::ostream &os, Animal const &anim);

#endif