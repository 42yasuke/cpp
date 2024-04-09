/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:50:08 by jose              #+#    #+#             */
/*   Updated: 2024/04/09 10:52:33 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor BitcoinExchange called" << std::endl;
	std::string const dataFileName(DATA_BASE);
	std::ifstream data_strm(dataFileName.c_str());
	if (!data_strm)
		throw std::runtime_error("Error: data.csv open failed");

	std::string	line;
	std::string	date;
	std::getline(data_strm, line);
	if (line.compare("date,exchange_rate") != 0)
		throw std::runtime_error("Error: first line of data.csv is wrong");
	while (std::getline(data_strm, date, ','))
	{
		if (!ft_isAGoodDate(date))
			throw std::runtime_error("Error: bad date => " + date);
		std::getline(data_strm, line);
		if (this->btcMap.find(date) != this->btcMap.end())
			throw std::runtime_error("Error: duplicate => " + date);
		if (!ft_isAGoodPrice(line))
			throw std::runtime_error("Error: bad input => " + date);
		float	price = strtof(line.c_str(), NULL);
		this->btcMap[date] = price;
	}
	data_strm.close();
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor BitcoinExchange called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &btc)
{
	(void)btc;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc)
{
	return ((void)btc, *this);
}

bool	BitcoinExchange::ft_isAGoodDate(std::string &date)
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

bool	BitcoinExchange::ft_isAGoodPrice(std::string &price)
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

void	BitcoinExchange::ft_treatmentInputFile(const std::string &inputFile)
{
	std::ifstream input_strm(inputFile.c_str());

	if (!input_strm)
		throw std::runtime_error("Error: input.txt open failed");
	std::string line;
	std::getline(input_strm, line);
	if (line.compare("date | value") != 0)
		throw std::runtime_error("Error: First line of input.txt is wrong");

	while (std::getline(input_strm, line))
	{
		try
		{
			std::string date = line.substr(0, 10);
			line = line.erase(0, 10);
			if (line.compare(0, 3, " | "))
				throw std::runtime_error("Error: bad format.");
			line.erase(0, 3);

			float value_btc = strtof(line.c_str(), NULL);
			if (!ft_isAGoodDate(date))
				throw std::runtime_error("Error: bad date => " + date);
			else if (value_btc < 0)
				throw std::runtime_error("Error: not a positive number.");
			else if (value_btc > 1000)
				throw std::runtime_error("Error: too large a number.");

			if (this->btcMap.find(date) == this->btcMap.end())
			{
				std::map<std::string, float>::iterator it = this->btcMap.lower_bound(date);
				if (it == this->btcMap.begin())
					throw std::runtime_error("Error: Date not found and no closest date available => " + date);
				--it;
				date = it->first;
			}
			std::cout << date << " => " << value_btc << " = " << this->btcMap[date] * value_btc << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	input_strm.close();
}

void	BitcoinExchange::ft_display(void)
{
	std::map<std::string, float>::iterator it = this->btcMap.begin();
	std::cout << "date,exchange_rate" << std::endl;
	while (it != this->btcMap.end())
	{
		std::cout << it->first << "," << it->second << std::endl;
		it++;
	}
}
