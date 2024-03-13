/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:03:03 by jose              #+#    #+#             */
/*   Updated: 2024/03/13 17:05:23 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() {}
		MutantStack(const MutantStack& copy) : std::stack<T>(copy){}
		virtual ~MutantStack<T>() {}
		MutantStack<T> &operator=(const MutantStack<T> &copy)
		{
			std::stack<T>::operator=(copy);
			return *this;
		}

		typedef typename std::deque<T>::iterator	iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};

#endif