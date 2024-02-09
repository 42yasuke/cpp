/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:56 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 17:32:06 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain	*myBrain;
	public:
		Dog();
		virtual ~Dog();
		Dog(Dog const &dog);
		Dog	&operator=(Dog const &dog);
		virtual void	makeSound(void) const;
		Brain	&getMybrain(void) const;
};

std::ostream	&operator<<(std::ostream &os, Dog const &dog);

#endif