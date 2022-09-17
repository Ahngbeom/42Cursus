/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:09:39 by bahn              #+#    #+#             */
/*   Updated: 2022/02/24 17:03:45 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : name(name)
{
	// std::cout << "Character Constructor called" << std::endl;
	for (size_t i = 0; i < AMATERIA_MAX; i++)
	{
		inven[i] = NULL;
	}
}

Character::Character(const Character& character) {
	// std::cout << "Character Copy Constructor called" << std::endl;
	*this = character;
}

Character::~Character()
{
	// std::cout << "Character Deconstructor called" << std::endl;
	for (size_t i = 0; i < AMATERIA_MAX; i++)
	{
		if (inven[i] != NULL)
			delete inven[i];
	}
}

Character&	Character::operator=(const Character& character) {
	// std::cout << "Character Assignment Operaotor called" << std::endl;
	if (this != &character) {
		this->name = character.getName();
		for (size_t i = 0; i < AMATERIA_MAX; i++)
		{
			if (character.inven[i] != NULL)
				this->inven[i] = character.inven[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (name);
}

void Character::equip(AMateria* m) {
	size_t	i = 0;

	while (inven[i] != NULL)
		i++;
	if (i < AMATERIA_MAX)
		inven[i] = m;
}

void Character::unequip(int idx) {
	(void)idx;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= AMATERIA_MAX) {
		std::cout << "Index Out Of Bounds." << std::endl;
	} 
	else {
		if (this->inven[idx] == NULL)
			std::cout << "Not Equipped Materia." << std::endl;
		else
			this->inven[idx]->use(target);
	}

	
}

