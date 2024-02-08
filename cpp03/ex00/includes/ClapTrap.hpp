/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:35:45 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 19:49:06 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string	Name;
		int	Hit;
		int	Energy;
		int	Attack;
		int	MaxHit;
	public :
		ClapTrap();
		ClapTrap(std::string n);
		~ClapTrap();
		ClapTrap(ClapTrap const &clap);
		ClapTrap	&operator=(ClapTrap const &clap);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string	ft_getName(void) const;
		int	ft_getEnergy(void) const;
		int	ft_getAttack(void) const;
		int	ft_getHit(void) const;
};

std::ostream	&operator<<(std::ostream &os, ClapTrap const &clap);

#endif