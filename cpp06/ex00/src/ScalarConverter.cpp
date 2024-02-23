/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:15:30 by jose              #+#    #+#             */
/*   Updated: 2024/02/23 19:22:37 by jralph           ###   ########.fr       */
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
			if (!i)
			{
				if (str[i] != '+' && str[i] != '-' && str[i] != '.')
					return UNKNOWN;
				else
					continue;
			}
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
	double	d;
	std::stringstream ss(str);
	if (ss.fail())
		throw StdStringStreamException();
	ss >> d;
	if (d < 0 || d > 255)
		std::cout << "char: Impossible" << std::endl;
	else if (d < 32 || d > 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::ft_float(std::string const &str)
{
	double	d;
	std::stringstream ss(str);
	if (ss.fail())
		throw StdStringStreamException();
	ss >> d;
	if (!str.compare("nanf"))
		(std::cout << "char: Impossible" << std::endl, std::cout << "int: Impossible" << std::endl);
	else
	{
		if (d < 0 || d > 255)
			std::cout << "char: Impossible" << std::endl;
		else if (d < 32 || d > 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
			std::cout << "int: Impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::ft_double(std::string const &str)
{
	double	d;
	std::stringstream ss(str);
	if (ss.fail())
		throw StdStringStreamException();
	ss >> d;
	if (!str.compare("nan"))
		(std::cout << "char: Impossible" << std::endl, std::cout << "int: Impossible" << std::endl);
	else
	{
		if (d < 0 || d > 255)
			std::cout << "char: Impossible" << std::endl;
		else if (d < 32 || d > 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
			std::cout << "int: Impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
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

const char*	ScalarConverter::StdStringStreamException::what() const throw()
{
	return "std::stringstream failded";
}
