/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:16:09 by jose              #+#    #+#             */
/*   Updated: 2024/02/26 12:12:47 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstring>
#include "limits.h"
#include <sstream>
#include <stdexcept>

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
		static void	printFloatAndDouble(double const &d);
		static void	printCharAndInt(double const &d);
		static int	getType(std::string const &str);
	public:
		static void	convert(std::string const &str);

	class StdStringStreamException: public std::exception
	{
		virtual const char*	what() const throw();
	};
};

#endif