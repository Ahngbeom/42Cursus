/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:12:46 by bahn              #+#    #+#             */
/*   Updated: 2022/02/24 17:04:57 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* bahn = new Character("bahn");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		bahn->equip(tmp);
		tmp = src->createMateria("cure");
		bahn->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		bahn->use(0, *bob);
		bahn->use(1, *bob);
		
		delete bob;
		delete bahn;
		delete src;
	}
	std::cout << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* bahn = new Character("bahn");
		ICharacter* bug = new Character("BUG");
		ICharacter* _42Seoul = new Character("42Seoul");
		
		bahn->equip(src->createMateria("ice"));
		bahn->equip(src->createMateria("cure"));
		bug->equip(src->createMateria("ice"));
		_42Seoul->equip(src->createMateria("cure"));
		
		bahn->use(0, *bug);
		bahn->use(1, *bug);
		bahn->use(2, *bug);
		bahn->use(3, *bug);
		bahn->use(4, *bug); // Index Out of Bounds.

		std::cout << std::endl;
		
		bug->use(0, *bahn);
		bahn->use(0, *bug);
		_42Seoul->use(0, *bahn);
		bahn->use(1, *_42Seoul);
		
		bahn->unequip(0); // Must Nothing Works.
		bahn->use(0, *bug);

		delete bahn;
		delete src;
		delete bug;
		delete _42Seoul;
	}
	return 0;
}
