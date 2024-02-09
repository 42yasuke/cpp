/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:14:59 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 15:30:43 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(Cat const &cat);
		Cat	&operator=(Cat const &cat);
		virtual void	makeSound(void) const;
};

#endif