/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:28:31 by jose              #+#    #+#             */
/*   Updated: 2024/03/04 20:44:01 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
# include <cctype>

template<typename T>
typename T::iterator easyfind(T	&container, int value)
{
	typename T::iterator	it = container.begin();
	while(it != container.end() && *it != value)
		it++;
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return it;
}

#endif