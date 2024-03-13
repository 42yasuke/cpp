/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:28:31 by jose              #+#    #+#             */
/*   Updated: 2024/03/13 15:49:27 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <iterator>
#include <vector>
#include <algorithm>

class Span
{
	private:
		Span();
		unsigned int	N;
		std::vector<int>	list;
	public:
		~Span();
		Span(unsigned int n);
		Span(Span const &copy);
		Span	&operator=(Span const &op);
		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		long long	myAbs(long long num);
		long long	shortestSpan(void);
		long long	longestSpan(void);
		unsigned int	getN(void) const;
		std::vector<int>	const &getList(void) const;
};

std::ostream	&operator<<(std::ostream &os, Span const &sp);

#endif