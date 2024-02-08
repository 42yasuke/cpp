/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:31:31 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 19:35:30 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &scav);
		ScavTrap	&operator=(ScavTrap const &scav);
		void	attack(const std::string& target);
		void	guardGate(void);
};

std::ostream	&operator<<(std::ostream &os, ScavTrap const &scav);

#endif