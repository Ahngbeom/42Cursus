/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:20:46 by bahn              #+#    #+#             */
/*   Updated: 2022/02/24 00:04:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Dog*	dog = new Dog();
	const Cat*	cat = new Cat();
	
	std::cout << std::endl;
	
	const Dog*	cloneDog = new Dog(*dog);
	const Cat*	cloneCat = new Cat(*cat);
	
	std::cout << std::endl;

	std::srand((unsigned int)time(NULL));
	
	dog->makeSound();
	cat->makeSound();
	
	std::cout << std::endl;
	
	delete dog;
	delete cat;

	std::cout << std::endl;

	cloneDog->makeSound();
	cloneCat->makeSound();
	
	std::cout << std::endl;

	delete cloneDog;
	delete cloneCat;

	return 0;
}
