/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 01:39:02 by jose              #+#    #+#             */
/*   Updated: 2024/02/27 22:21:37 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <stdexcept>
#include <cstdlib> 

class Base
{
	public:
		virtual ~Base();

};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif

