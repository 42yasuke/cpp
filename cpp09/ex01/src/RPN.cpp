/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:50:08 by jose              #+#    #+#             */
/*   Updated: 2024/04/09 20:11:35 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{	
}

RPN::~RPN()
{
}
RPN::RPN(RPN const &rpn)
{
	(void)rpn;
}
RPN	&RPN::operator=(RPN const &rpn)
{
	return ((void)rpn, *this);
}

RPN::RPN(std::string const &str)
{
	if (!this->ft_isAgoodArg(str))
		throw std::invalid_argument("Error: invalid argument");
	std::string	rev = this->ft_reverseIt(str);
	for(size_t i = 0; i < rev.length(); i++)
	{
		if (rev[i] != ' ')
		{
			if (isdigit(rev[i]))
				this->myStack.push(rev[i] - '0');
			else
				this->myStack.push(rev[i]);
		}
	}
	int	res = this->myStack.top();
	int	tmp = 0;
	this->myStack.pop();
	while (!this->myStack.empty())
	{
		tmp = this->myStack.top();
		this->myStack.pop();
		switch (this->myStack.top())
		{
			case '+':
				res += tmp;
				break;
			case '-':
				res -= tmp;
				break;
			case '*':
				res *= tmp;
				break;
			default:
				if (!tmp)
					throw std::logic_error("Error: Division by zero is forbidden");
				res /= tmp;
				break;
		}
		this->myStack.pop();
	}
	std::cout << res << std::endl;
}

bool	RPN::ft_isAgoodArg(std::string const &str) const
{
	if (!isdigit(str[0]))
		return false;
	if (str.size() > 1 && (str[1] != ' ' || str.size() < 5))
		return false;
	std::string	copy(str);
	copy = copy.substr(2);
	
	while (copy.size() > 2)
	{
		if (!isdigit(copy[0]) || copy[1] != ' ' || !this->ft_isAnOperation(copy[2]))
			return false;
		copy = copy.substr(3);
		if (copy[0] == ' ')
			copy = copy.substr(1);
	}
	return true;
}

bool	RPN::ft_isAnOperation(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/' );
}

std::string	RPN::ft_reverseIt(std::string const &str) const
{
	std::string	copy(str);
	size_t	len =  str.size();
	for (size_t i = 0; i < len; i++)
		copy[i] = str[len - 1 - i];
	return copy;
}

void	RPN::ft_display(void)
{
}
