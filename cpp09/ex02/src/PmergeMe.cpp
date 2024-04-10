/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:08:15 by jralph            #+#    #+#             */
/*   Updated: 2024/04/10 19:14:46 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &pmg)
{
	(void)pmg;
}
PmergeMe	&PmergeMe::operator=(PmergeMe const &pmg)
{
	return ((void)pmg, *this);
}

PmergeMe::PmergeMe(int ac, char **av)
{
	if (!ft_isAGoodArg(ac, av))
		throw std::invalid_argument("Error: invalid argument");
	for (int i = 1; i < ac; i++)
	{
		this->myVect.push_back(atoi(av[i]));
		this->myDeq.push_back(atoi(av[i]));
	}

	std::cout << "Before: ";
	this->ft_display(this->myVect);

	clock_t start = clock();
	this->myVect = this->ft_mergeInsertionSort(this->myVect);
	clock_t end = clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 100000;

	start = clock();
	this->myDeq = this->ft_mergeInsertionSort(this->myDeq);
	end = clock();

	std::cout << "After: ";
	this->ft_display(this->myVect);

	std::cout << "Time to process a range of " << this->myVect.size() << " elements with std::vector : " << duration << " us\n";
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 100000;
	std::cout << "Time to process a range of " << this->myDeq.size() << " elements with std::deque : " << duration << " us\n";
}

bool	PmergeMe::ft_isAGoodArg(int ac, char **av) const
{
	for (int i = 1; i < ac; i++)
	{
		long	tmp = atol(av[i]);
		if (!tmp && strcmp(av[i], "0"))
			return false;
		if (tmp < 0 || tmp > INT32_MAX)
			return false;
	}
	return true;
}

template<typename T>T	PmergeMe::ft_mergeInsertionSort(T& arr)
{
	int n = arr.size();
	int i = 0;
	if (n <= 1)
		return arr;
	
	T	lowest, biggest;
	if (n % 2 != 0)
	{
		lowest.push_back(arr[i]);
		++i;
	}
	for (; i < n; i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			biggest.push_back(arr[i]);
			lowest.push_back(arr[i + 1]);
		} 
		else
		{
			lowest.push_back(arr[i + 1]);
			biggest.push_back(arr[i]);
		}
	}
	T	biggest_sorted = ft_mergeInsertionSort(biggest);
	typename T::iterator	it;

	for (size_t i = 0; i < lowest.size(); ++i)
	{
		it = std::lower_bound(biggest_sorted.begin(), biggest_sorted.end(), lowest[i]);
		biggest_sorted.insert(it, lowest[i]);
	}
	return biggest_sorted;
}

template<typename T>void	PmergeMe::ft_display(T& arr) const
{
	for(typename T::const_iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
