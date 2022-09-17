/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:20:46 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 21:40:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;

	/*
		[Static Binding vs Dynamic Binding] Comparison TEST
	*/
	{
		const Animal	meta = Animal();
		const Animal	j = Dog();
		const Animal	i = Cat();
		
		std::cout << j.getType() << " " << std::endl;
		std::cout << i.getType() << " " << std::endl;
		std::cout << meta.getType() << " " << std::endl;

		i.makeSound();
		j.makeSound();
		meta.makeSound();
	}
	return 0;
}
