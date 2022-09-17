/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:26:03 by bahn              #+#    #+#             */
/*   Updated: 2022/02/24 00:00:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] Constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& dog) : Animal() {
	std::cout << "[Dog] Copy Constructor called" << std::endl;
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "[Dog] Deconstructor called" << std::endl;
	delete brain;
}

Dog&	Dog::operator=(const Dog& dog) {
	std::cout << "[Dog] Assignment Operator called" << std::endl;
	if (this != &dog) {
		this->type = dog.getType();
		this->brain = new Brain(*dog.brain);
	}
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << getType() + " : ";
	std::cout << "WOOF! WOOF! ";

	getIdea(rand() % 100);
}

void	Dog::getIdea(const int& index) const {
	std::cout << "(" + brain->comeToIdea(index) + ")" << std::endl;
}
