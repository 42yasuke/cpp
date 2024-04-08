/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:31:24 by jose              #+#    #+#             */
/*   Updated: 2024/04/08 19:11:42 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}
Serializer::Serializer(Serializer const &sr)
{
	(void)sr;
}
Serializer	&Serializer::operator=(Serializer const &sr)
{
	return ((void)sr, *this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream &os, Serializer const &sr)
{
	return ((void)sr, os);
}
