/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:50:08 by jose              #+#    #+#             */
/*   Updated: 2024/03/04 12:02:25 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	const &min(T const& a, T const& b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T	const &max(T const& a, T const& b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif