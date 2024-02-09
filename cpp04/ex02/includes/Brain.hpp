/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:09 by jralph            #+#    #+#             */
/*   Updated: 2024/02/09 16:36:35 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string	*ideas;
	public:
		Brain();
		~Brain();
		Brain(Brain const &br);
		Brain	&operator=(Brain const &br);
		std::string	*getIdeas(void) const;
};

std::ostream	&operator<<(std::ostream &os, Brain const &br);

#endif