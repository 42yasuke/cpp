/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:55:35 by jose              #+#    #+#             */
/*   Updated: 2024/04/08 20:14:52 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0), list(0)
{
	std::cout << "Default constructor Sapn called" << std::endl;
}

Span::~Span()
{
	std::cout << "Destructor Sapn called" << std::endl;
}
Span::Span(unsigned int n) : N(n), list(std::vector<int>())
{
	std::cout << "Constructor Sapn with parameter " << n << " called" << std::endl;
}
Span::Span(Span const &copy) : N(0), list(std::vector<int>())
{
	std::cout << "Constructor Span by copy called" << std::endl;
	*this = copy;
}
Span	&Span::operator=(Span const &op)
{
	this->N = op.N;
	this->list.assign(op.list.begin(), op.list.end());
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->list.size() >= this->N)
		throw std::out_of_range("Error: Span already full");
	this->list.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; it++)
	{
		if (this->list.size() >= this->N)
			throw std::out_of_range("Error: Span already full");
		addNumber(*it);
	}
}

long long	Span::myAbs(long long num)
{
	return (num < 0)? -num : num;
}

long long	Span::shortestSpan(void)
{
	long long	res = 0;
	if (this->list.size() < 2)
		throw std::logic_error("Error: not enough number");
	std::vector<int> list_sorted = this->list;
	std::sort(list_sorted.begin(), list_sorted.end());
	res = myAbs(*(this->list.begin()) - *(this->list.end() - 1));
	for (std::vector<int>::iterator it = this->list.begin(); it + 1 != this->list.end(); it++)
	{
		if (myAbs(*(it + 1) - *it) < res)
			res = myAbs(*(it + 1) - *it);
	}
	return res;
}
long long	Span::longestSpan(void)
{
	if (this->list.size() < 2)
		throw std::logic_error("Error: not enough number");
	std::vector<int>::iterator min = std::min_element(this->list.begin(), this->list.end());
	std::vector<int>::iterator max = std::max_element(this->list.begin(), this->list.end());
	return myAbs(*max - *min);
}
unsigned int	Span::getN(void) const
{
	return (this->N);
}

std::vector<int>	const &Span::getList(void) const
{
	return (this->list);
}

std::ostream	&operator<<(std::ostream &os, Span const &sp)
{
	os << "*** Span info ***" << std::endl;
	os << "limit N = " << sp.getN() << std::endl;
	os << "[ ";
	std::vector<int> vec = std::vector<int> (sp.getList());
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		os << *it;
		if (it + 1 != vec.end())
			os << ", ";
	}
	return (os << " ]", os);
}