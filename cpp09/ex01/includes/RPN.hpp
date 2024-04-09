/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:02:16 by jralph            #+#    #+#             */
/*   Updated: 2024/04/09 20:12:34 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <stack>
#include <cctype>
#include <cstring>

class RPN
{
	private:
		std::stack<int>	myStack;
		RPN();
		RPN(RPN const &rpn);
		RPN	&operator=(RPN const &rpn);
		void	ft_display(void);
	public:
		~RPN();
		RPN(std::string const &str);
		bool	ft_isAgoodArg(std::string const &str) const;
		bool	ft_isAnOperation(char c) const;
		std::string	ft_reverseIt(std::string const &str) const;
};

#endif