/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:59 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 17:31:11 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain	*myBrain;
	public:
		Cat();
		virtual ~Cat();
		Cat(Cat const &cat);
		Cat	&operator=(Cat const &cat);
		virtual void	makeSound(void) const;
		Brain	&getMybrain(void) const;
};

std::ostream	&operator<<(std::ostream &os, Cat const &cat);

#endif