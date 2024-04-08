/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:48:03 by jose              #+#    #+#             */
/*   Updated: 2024/04/08 19:06:29 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct data_t
{
	std::string	str;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &sr);
		Serializer	&operator=(Serializer const &sr);
	public:
		~Serializer();
		static uintptr_t	serialize(Data* ptr);
		static Data	*deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &os, Serializer const &sr);

#endif

