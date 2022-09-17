/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:24:14 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:46:55 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "[Animal] Constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) {
	std::cout << "[Animal] Copy Constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "[Animal] Deconstructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& animal) {
	std::cout << "[Animal] Assignment Operator called" << std::endl;
	if (this != &animal) {
		this->type = animal.getType();
	}
	return (*this);
}

std::string	Animal::getType( void ) const {
	return (type);
}
