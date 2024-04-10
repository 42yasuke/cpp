/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:40:16 by jose              #+#    #+#             */
/*   Updated: 2024/04/10 15:59:30 by jralph           ###   ########.fr       */
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
		~BitcoinExchange();

		bool	ft_isAGoodDate(std::string &date) const;
		bool	ft_isAGoodPrice(std::string &price) const;
		void	ft_treatmentInputFile(const std::string &inputFile);
		void	ft_display(void);
};

#endif