/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:15:27 by jose              #+#    #+#             */
/*   Updated: 2024/02/01 13:26:17 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
}

Contact::Contact(std::string fname, std::string lname, std::string nname,
	std::string pnumber, std::string dsecret)
{
	this->_first_name = fname;
	this->_last_name = lname;
	this->_nickname = nname;
	this->_phone_number = pnumber;
	this->_darkest_secret = dsecret;
}

Contact::~Contact()
{
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}
