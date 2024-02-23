/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:15:30 by jose              #+#    #+#             */
/*   Updated: 2024/02/23 02:48:42 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	ScalarConverter::getType(std::string const &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	bool	only_digit = true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (!i && (str[i] != '+' || str[i] != '-' || str[i] != '.'))
				return UNKNOWN;
			if (str[i] == '.')
			{
				if (!only_digit)
					return UNKNOWN;
				only_digit = false;
			}
			else if (str[i] == 'f' && i == str.length() - 1)
				return FLOAT;
			else
				return UNKNOWN;
		}
	}
	if (only_digit)
		return INT;
	return DOUBLE;
}

void	ScalarConverter::ft_char(std::string const &str)
{
	char c = str[0];
	if (static_cast<int> (c) < 32 || static_cast<int> (c) > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}
void	ScalarConverter::ft_int(std::string const &str)
{
	std::cout << str << " : c un int" << std::endl;
}

void	ScalarConverter::ft_float(std::string const &str)
{
	std::cout << str << " : c un float" << std::endl;
}

void	ScalarConverter::ft_double(std::string const &str)
{
	std::cout << str << " : c un double" << std::endl;
}

void	ScalarConverter::ft_unknwon(std::string const &str)
{
	std::cout << "Error: "<< str << " : type unknown" << std::endl;
}

void	ScalarConverter::convert(std::string const &str)
{
	int	type = getType(str);
	FctPtr ft_tabConverter[5] = {&ScalarConverter::ft_char, &ScalarConverter::ft_int, 
		&ScalarConverter::ft_float, &ScalarConverter::ft_double, &ScalarConverter::ft_unknwon};
	return ft_tabConverter[type](str);
}
