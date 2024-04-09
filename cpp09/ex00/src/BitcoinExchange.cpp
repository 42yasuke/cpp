/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:50:08 by jose              #+#    #+#             */
/*   Updated: 2024/04/09 02:09:11 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor BitcoinExchange called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &btc)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc)
{
	return ((void)btc, *this);
}

BitcoinExchange()
{
	std::string const dataFileName("../data.csv");
	std::ifstream data_strm(dataFileName.c_str());
	if (!data_strm)
		throw std::runtime_error("data.csv open failed");

	std::string	line;
	std::string	date;
	std::getline(data_strm, line);
	if (line.compare("date,exchange_rate") != 0)
		throw std::runtime_error("First line of data.csv is wrong");
	while (std::getline(data_strm, date, ','))
	{
		if (!isValidDate(date))
			throw std::runtime_error("Error: bad date => " + date);
		std::getline(data_strm, line);
		if (this->btcMap.find(date) != this->btcMap.end())
			throw std::runtime_error("Error: duplicate => " + date);
		if (!isValidPrice(line))
			throw std::runtime_error("Error: bad input => " + date);
		float	price = strtof(line.c_str(), NULL);
		this->btcMap[date] = price;
	}
	data_strm.close();
}

bool	BitcoinExchange::isValidDate(std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2023)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

bool	BitcoinExchange::isValidPrice(std::string &price)
{
	if (price.size() == 0 || price.find(".") != price.rfind("."))
		return false;
	for (size_t i = 0; i < price.size(); i++)
	{
		if (!isdigit(price[i]) && price[i] != '.')
			return false;
	}
	if (strtof(price.c_str(), NULL) > FLT_MAX)
		return false;
	return true;
}

void	BitcoinExchange::processInputFile(const std::string &inputFile)
{
	
}

void	BitcoinExchange::ft_display(void)
{
	
}