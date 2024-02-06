/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:43:22 by jralph            #+#    #+#             */
/*   Updated: 2024/02/07 00:08:55 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	std::cout<<a.getRawBits()<<std::endl;
	std::cout<<b.getRawBits()<<std::endl;
	std::cout<<c.getRawBits()<<std::endl;
	return (0);
}
