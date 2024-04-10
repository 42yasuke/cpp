/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:50:08 by jose              #+#    #+#             */
/*   Updated: 2024/04/10 12:09:09 by jose             ###   ########.fr       */
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
	for(size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			if (isdigit(str[i]))
				this->myStack.push(str[i] - '0');
			else
			{
				int tmp = this->myStack.top();
				this->myStack.pop();
				switch (str[i])
				{
					case '+':
						tmp += this->myStack.top();
						break;
					case '-':
						tmp = this->myStack.top() - tmp;
						break;
					case '*':
						tmp *= this->myStack.top();
						break;
					default:
						if (!tmp)
							throw std::logic_error("Error: Division by zero is forbidden");
						tmp = this->myStack.top() / tmp;
						break;
				}
				this->myStack.pop();
				this->myStack.push(tmp);
			}
		}
	}
}

bool	RPN::ft_isAgoodArg(std::string const &str) const
{
	int	nb_int = 0;
	int	nb_op = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			if (isdigit(str[i]))
				nb_int++;
			else if (this->ft_isAnOperation(str[i]))
			{
				nb_op++;
				if (nb_int < nb_op + 1)
					return false;
			}
			else
				return false;
		}
	}
	return (nb_int == nb_op + 1);
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

void	RPN::ft_display(void) const
{
	std::cout << this->myStack.top() << std::endl;
}
