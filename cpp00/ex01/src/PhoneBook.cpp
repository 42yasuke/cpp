/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:17:21 by jose              #+#    #+#             */
/*   Updated: 2024/02/01 10:25:13 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_book_size = 0;
	this->_the_oldest = 0;
}

PhoneBook::~PhoneBook()
{
}

std::string	ft_give_me(std::string name)
{
	std::string	ret = "";

	std::cout << "please give a " << name << std::endl;
	getline(std::cin, ret);
	while (!ret.size())
		getline(std::cin, ret);
	return (ret);
}

void PhoneBook::ft_add_contact(void)
{
	std::string	tab[5];

	tab[0] = ft_give_me("first name");
	tab[1] = ft_give_me("last name");
	tab[2] = ft_give_me("nickname");
	tab[3] = ft_give_me("phone number");
	tab[4] = ft_give_me("darkest secret");

	if (this->_book_size < 8)
	{
		this->_book[this->_book_size] = Contact(tab[0], tab[1], tab[2], tab[3], tab[4]);
		this->_book_size++;
	}
	else
	{
		this->_book[this->_the_oldest] = Contact(tab[0], tab[1], tab[2], tab[3], tab[4]);
		if (++this->_the_oldest == 8)
			this->_the_oldest = 0;
	}
}

void	PhoneBook::ft_display_contact(int i, Contact cont) const
{
	std::string (Contact::*get_name)(void) const;

	std::cout << "         " << i + 1 << "|";
	for (int k = 0; k < 3; k++)
	{
		if (!k)
			get_name = &Contact::get_first_name;
		else if (k == 1)
			get_name = &Contact::get_last_name;
		else
			get_name = &Contact::get_nickname;
		for (std::size_t j = 0; 10 > j + (cont.*get_name)().size(); j++)
			std::cout << " ";
		if ((cont.*get_name)().size() < 11)
			std::cout << (cont.*get_name)();
		else
		{
			std::cout << (cont.*get_name)().substr(0, 9);
			std::cout << ".";
		}
		if (k != 2)
			std::cout << "|";
	}
	std::cout << std::endl;
}

void	PhoneBook::ft_display_contact(Contact cont) const
{
	std::cout << "*********** CONTACT INFO **********" << std::endl;
	std::cout << "first name : " << cont.get_first_name() << std::endl;
	std::cout << "last name : " << cont.get_last_name() << std::endl;
	std::cout << "nickname : " << cont.get_nickname() << std::endl;
	std::cout << "phone number : " << cont.get_phone_number() << std::endl;
	std::cout << "darkest secret : " << cont.get_darkest_secret() << std::endl;
}

void PhoneBook::ft_display_book(void) const
{
	std::cout << std::endl << "********** ALL CONTACTS **********" << std::endl;
	if (!this->_book_size)
		std::cout << std::endl << "          phonebook empty          " << std::endl;
	for (int i = 0; i < this->_book_size; i++)
		ft_display_contact(i, this->_book[i]);
}

int PhoneBook::ft_make_choice(void) const
{
	int	choice = 0;
	int	bad_choice = 0;

	if (!this->_book_size)
		return (-1);
	std::cout << "please make a correct choice, you have 3 tries" << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice > this->_book_size)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		if (++bad_choice == 3)
			break ;
		std::cin >> choice;
	}
	if (bad_choice == 3)
	{
		std::cout << "too many bad choices";
		return (-1);
	}
	return (choice - 1);
}

void PhoneBook::ft_search_contact(void) const
{
	int choice;

	ft_display_book();
	choice = ft_make_choice();
	if (choice != -1)
		ft_display_contact(this->_book[choice]);
}
