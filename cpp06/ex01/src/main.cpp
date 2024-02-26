/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/02/26 13:38:27 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	*obj = new Data();
	std::cout << "> Data object created\n" << std::endl;

	obj->str = "cette exercice est vraiment chelou";
	std::cout << "Data string: " << obj->str << std::endl;
	std::cout << "Data Address: " << obj << std::endl;

	uintptr_t	raw = Serializer::serialize(obj);
	std::cout << "\n> Serialized: " << raw << std::endl;

	obj = Serializer::deserialize(raw);
	std::cout << "\n> After deserialize: " << std::endl;

	std::cout << "\nData string: " << obj->str << std::endl;
	std::cout << "Data Address: " << obj << std::endl;

	delete obj;
	return (0);
}