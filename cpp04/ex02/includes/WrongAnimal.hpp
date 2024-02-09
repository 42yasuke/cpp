/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:43 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 15:58:28 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Brain.hpp"

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(std::string t);
		WrongAnimal(WrongAnimal const &wanim);
		WrongAnimal	&operator=(WrongAnimal const &wanim);
		std::string	getType(void) const;
		void	makeSound(void) const;
};

std::ostream	&operator<<(std::ostream &os, WrongAnimal const &wanim);

#endif