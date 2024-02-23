/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:16:09 by jose              #+#    #+#             */
/*   Updated: 2024/02/23 02:24:56 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstring>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define UNKNOWN 4

typedef void (*FctPtr)(std::string const&);

class ScalarConverter
{
	private:
		static void	ft_char(std::string const &str);
		static void	ft_int(std::string const &str);
		static void	ft_float(std::string const &str);
		static void	ft_double(std::string const &str);
		static void	ft_unknwon(std::string const &str);
		static int	getType(std::string const &str);
	public:
		static void	convert(std::string const &str);
};

#endif