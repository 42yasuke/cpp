/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:07:43 by jose              #+#    #+#             */
/*   Updated: 2024/02/06 03:00:37 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

std::string	*ft_copy(char *str)
{
	std::string	*ret = new std::string();
	for(int i = 0; str[i]; i++)
		*(ret)+=str[i];
	return (ret);
}

void	ft_replace(std::string *file, std::string *o_word, std::string *r_word)
{
	std::ifstream	infile(file->c_str());
	if (!infile)
	{
		std::cout << "error : open failed : file " << *file << std::endl;
		return ;
	}
	std::string	file_out = std::string(*file);
	file_out.append(".replace");
	std::ofstream	outfile(file_out.c_str());
	if (!outfile)
	{
		infile.close();
		std::cout << "error : open failed : file " << file_out << std::endl;
		return ;
	}
	char	c;
	std::string	word = std::string();
	while (infile.get(c))
	{
		if ((*o_word)[0] == c)
		{
			word+=c;
			while (word.size() != o_word->size() && infile.get(c))
				word+=c;
			if (word == *o_word)
				outfile << *r_word;
			else
				outfile << word;
			word.erase();
		}
		else
			outfile << c;
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "error : invalid number of arguments" << std::endl, 1);
	if (!strlen(av[1]) || !strlen(av[2]) || !strlen(av[3]))
		return (std::cout << "error : invalid arguments" << std::endl, 1);

	std::string	*file = ft_copy(av[1]);
	std::string	*origin_word = ft_copy(av[2]);
	std::string	*replace_word = ft_copy(av[3]);

	ft_replace(file, origin_word, replace_word);
	return (delete file, delete origin_word, delete replace_word, 0);
}
