/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:28:31 by jose              #+#    #+#             */
/*   Updated: 2024/03/13 13:19:13 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <algorithm>

template <typename T>
void easyfind(T& container , int value){
	try
	{
		typename T::iterator pos = std::find(container.begin(), container.end(), value);
		if (pos == container.end())
			throw std::exception();
		else
			std::cout << "Value found at index: " << std::distance(container.begin(), pos) << std::endl;
	}
	catch (std::exception &e)
	{
			std::cerr << "Error : " << value << " not found" << std::endl;
	} 
};

#endif