/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:20:46 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:16:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include <cstdlib>
#include <ctime>

# define ANIMAL_COUNT 10

int main()
{
	std::srand(time(NULL));
	
	std::cout << "===================================================================" << std::endl;
	
	{
		const Animal*	animals[ANIMAL_COUNT];
	
		for (size_t i = 0; i < ANIMAL_COUNT; i++)
		{
			if (i < ANIMAL_COUNT / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (size_t i = 0; i < ANIMAL_COUNT; i++)
		{
			std::cout << animals[i]->getType() + ": ";
			animals[i]->makeSound();
			animals[i]->getIdea(std::rand() % IDEAS_MAX);
		}
		
		for (size_t i = 0; i < ANIMAL_COUNT; i++)
		{
			delete animals[i];
		}
	}

	std::cout << "===================================================================" << std::endl;

	{
		const Dog*	dog = new Dog();
		const Cat*	cat = new Cat();

		std::cout << dog->getType() << "(" << &dog << "): ";
		dog->makeSound();
		dog->getIdea(std::rand() % IDEAS_MAX);
		
		std::cout << cat->getType() << "(" << &cat << "): ";
		dog->makeSound();
		cat->getIdea(std::rand() % IDEAS_MAX);
	
		std::cout << std::endl;

		Dog*	cloneDog = new Dog(*dog);
		Cat*	cloneCat = new Cat(*cat);
		
		std::cout << cloneDog->getType() << "(" << &cloneDog << "): ";
		cloneDog->makeSound();
		cloneDog->getIdea(std::rand() % IDEAS_MAX);
		
		std::cout << cloneCat->getType() << "(" << &cloneCat << "): ";
		cloneCat->makeSound();
		cloneCat->getIdea(std::rand() % IDEAS_MAX);

		delete  dog;
		delete	cat;
		delete	cloneDog;
		delete	cloneCat;
	}

	std::cout << "===================================================================" << std::endl;

	return 0;
}
