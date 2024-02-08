/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:48:12 by jralph            #+#    #+#             */
/*   Updated: 2024/02/08 20:16:04 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a;
	FragTrap	b("Morgan");
	ClapTrap	c("Hugues");
	ScavTrap	d("Ben");

	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout<<"          FIGHT          "<<std::endl;

	b.takeDamage(3);
	std::cout << b << std::endl;
	b.takeDamage(20);
	std::cout << b << std::endl;
	b.beRepaired(3);
	std::cout << b << std::endl;
	b.attack("Eric");
	b.attack("Eric");
	std::cout << b << std::endl;
	b.attack("Eric");
	std::cout << b << std::endl;
	b.beRepaired(100);
	std::cout << b << std::endl;
	b.attack("Eric");
	return (0);
}
