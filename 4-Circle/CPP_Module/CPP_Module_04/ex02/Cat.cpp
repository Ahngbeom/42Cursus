/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:26:03 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:58:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] Constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& cat) : Animal() {
	std::cout << "[Cat] Copy Constructor called" << std::endl;
	*this = cat;
}

Cat::~Cat()
{
	std::cout << "[Cat] Deconstructor called" << std::endl;
	delete brain;
}

Cat&	Cat::operator=(const Cat& cat) {
	std::cout << "[Cat] Assignment Operator called" << std::endl;
	if (this != &cat) {
		this->type = cat.getType();
		this->brain = new Brain(*cat.brain);
	}
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << getType() + " : ";
	std::cout << "MEOW~ MEOW~ ";

	getIdea(rand() % 100);
}

void	Cat::getIdea(const int& index) const {
	std::cout << "(" + brain->comeToIdea(index) + ")" << std::endl;
}
