/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:35:13 by jose              #+#    #+#             */
/*   Updated: 2024/03/04 16:57:11 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template<typename T>
class Array
{
	protected:
		T	*tab;
		unsigned	int _size;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(Array const &ar);
		Array	&operator=(Array const &ar);
		T	&operator[](unsigned int index);
		unsigned int	size(void) const;
};

template<typename T>
Array<T>::Array()
{
	std::cout << "Default constructor Array called" << std::endl;
	this->tab = new T[0];
	if (!this->tab)
		throw std::exception();
	this->_size = 0;
}
template<typename T>
Array<T>::~Array()
{
	std::cout << "Destructor Array called" << std::endl;
	delete[] this->tab;
}
template<typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Constructor Array with parameter " << n << " called" << std::endl;
	this->_size = n;
	this->tab = new T[n];
	if (!this->tab)
		throw std::exception();
	T	*tmp = new T();
	if (!tmp)
		throw std::exception();
	for (unsigned int i = 0; i < n; i++)
		this->tab[i] = *tmp;
	delete tmp;
}

template<typename T>
Array<T>::Array(Array const &ar)
{
	std::cout << "Constructor Array by copy called" << std::endl;
	this->_size = 0;
	this->tab = NULL;
	*this = ar;
}
template<typename T>
Array<T>	&Array<T>::operator=(Array const &ar)
{
	this->_size = ar.size();
	if (this->tab)
		delete[] tab;
	this->tab = new T[ar.size()];
	if (!this->tab)
		throw std::exception();
	for (unsigned int i = 0; i < ar.size(); i++)
		this->tab[i] = ar.tab[i];
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index < this->_size)
		return (this->tab[index]);
	throw std::exception();
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
std::ostream&	operator<<(std::ostream& os, Array<T> &ar)
{
	os << "[ ";
	for (unsigned int i = 0; i < ar.size(); i++)
	{
		os << ar[i];
		if (i != ar.size() - 1)
			os << ", ";
	}
	os << " ]" << std::endl;
	return (os);
}

#endif