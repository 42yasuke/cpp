/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:02:16 by jralph            #+#    #+#             */
/*   Updated: 2024/04/10 19:04:30 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <stack>
#include <cctype>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <stdint.h>

class PmergeMe
{
	private:
		std::vector<int> myVect;
		std::deque<int> myDeq;

		PmergeMe();
		PmergeMe(PmergeMe const &othepmgr);
		PmergeMe	&operator=(PmergeMe const &pmg);
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		template<typename T>T	ft_mergeInsertionSort(T& arr);
		bool	ft_isAGoodArg(int ac, char **av) const;
		template<typename T>void	ft_display(T& arr) const;
};

#endif