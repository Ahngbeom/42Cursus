/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:30:52 by bahn              #+#    #+#             */
/*   Updated: 2022/02/24 16:36:00 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource Constructor called" << std::endl;
	for (size_t i = 0; i < AMATERIA_MAX; i++)
	{
		srcs[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource Constructor called" << std::endl;
	for (size_t i = 0; i < AMATERIA_MAX; i++)
	{
		delete srcs[i];
	}
}

void MateriaSource::learnMateria(AMateria* mater) {
	size_t	i;

	for (i = 0; i < AMATERIA_MAX && srcs[i] != NULL; i++)
	{
		if (srcs[i]->getType().compare(mater->getType()) == 0)
			return ;
	}
	if (i < AMATERIA_MAX)
		srcs[i] = mater;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (std::size_t i = 0; i < AMATERIA_MAX && srcs[i] != NULL; i++) {
		if (type.compare(srcs[i]->getType()) == 0) {
			return (srcs[i]->clone());
		}
	}
	return (NULL);
}
