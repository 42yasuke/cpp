/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:15:10 by jralph            #+#    #+#             */
/*   Updated: 2024/03/04 12:28:40 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int tab[4] = {1, 2, 3, 4};
	iter<int>(tab, 4, ft_display);
	std::string ts[3] = {"Wesh", "alors ?"};
	iter<std::string>(ts, 3, ft_display);
}