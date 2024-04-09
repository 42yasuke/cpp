/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:40:16 by jose              #+#    #+#             */
/*   Updated: 2024/04/09 01:05:47 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <float.h>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> btcMap;
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &btc);
		BitcoinExchange &operator=(const BitcoinExchange &btc);

	public:
		BitcoinExchange(std::string const &dataFileName);
		~BitcoinExchange();

		bool	isValidDate(std::string &date);
		bool	isValidPrice(std::string &price);
		void	processInputFile(const std::string &inputFile);
		void	ft_display(void);
};

#endif