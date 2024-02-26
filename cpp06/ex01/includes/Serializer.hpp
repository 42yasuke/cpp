/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:48:03 by jose              #+#    #+#             */
/*   Updated: 2024/02/26 13:41:20 by jose             ###   ########.fr       */
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
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data	*deserialize(uintptr_t raw);
};

#endif

