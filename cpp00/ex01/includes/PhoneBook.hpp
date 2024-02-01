/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:44 by jose              #+#    #+#             */
/*   Updated: 2024/02/01 00:11:32 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int	_book_size;
		int	_the_oldest;
		Contact _book[8];

		void	ft_display_contact(int i, Contact cont) const;
		void	ft_display_contact(Contact cont) const;
		void	ft_display_book(void) const;
		int		ft_make_choice(void) const;
	public:
		PhoneBook();
		~PhoneBook();
		void	ft_add_contact(void);
		void	ft_search_contact(void) const;
};

#endif