/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:02:16 by jralph            #+#    #+#             */
/*   Updated: 2024/04/10 11:23:01 by jose             ###   ########.fr       */
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
	public:
		~RPN();
		RPN(std::string const &str);
		bool	ft_isAgoodArg(std::string const &str) const;
		bool	ft_isAnOperation(char c) const;
		std::string	ft_reverseIt(std::string const &str) const;
		void	ft_display(void) const;
};

#endif