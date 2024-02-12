/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:56:02 by jose              #+#    #+#             */
/*   Updated: 2024/02/12 14:41:49 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	(*materials[4]);
	public:
		Character();
		Character(std::string const &str);
		virtual ~Character();
		Character(Character const &charac);
		Character	&operator=(Character const &charac);
		virtual std::string const & getName() const;
		std::string	const getTypeM(int idx) const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

std::ostream 	&operator<<(std::ostream &os, Character const &charac);

#endif