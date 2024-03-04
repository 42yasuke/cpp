/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:50:08 by jose              #+#    #+#             */
/*   Updated: 2024/03/04 12:27:20 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void	iter(T *tab, int length, void(*f)(T const&))
{
	for (int i = 0; i < length; i++)
		f(tab[i]);

}

template <typename T>
void ft_display(T const& t)
{
	std::cout << t << std::endl;
}

#endif