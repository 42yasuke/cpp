/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:40:16 by jose              #+#    #+#             */
/*   Updated: 2024/04/09 10:49:08 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <float.h>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#define DATA_BASE "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, float> btcMap;
		BitcoinExchange(BitcoinExchange const &btc);
		BitcoinExchange &operator=(const BitcoinExchange &btc);

	public:
		BitcoinExchange();
		BitcoinExchange(std::string const &dataFileName);
		~BitcoinExchange();

		bool	ft_isAGoodDate(std::string &date);
		bool	ft_isAGoodPrice(std::string &price);
		void	ft_treatmentInputFile(const std::string &inputFile);
		void	ft_display(void);
};

#endif