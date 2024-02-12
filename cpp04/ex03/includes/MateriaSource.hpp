/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:12:13 by jose              #+#    #+#             */
/*   Updated: 2024/02/12 11:53:12 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	(*materials)[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(MateriaSource const &mat);
		MateriaSource	&operator=(MateriaSource const &mat);
		virtual void	learnMateria(AMateria*);
		virtual AMateria	*createMateria(std::string const & type);
		std::string	const getTypeM(int idx) const;
};

std::ostream	&operator<<(std::ostream &os, MateriaSource const &mat);

#endif