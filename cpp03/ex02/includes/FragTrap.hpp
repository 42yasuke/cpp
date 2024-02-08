/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:55:08 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 20:02:29 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &scav);
		FragTrap	&operator=(FragTrap const &scav);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

std::ostream	&operator<<(std::ostream &os, FragTrap const &scav);

#endif