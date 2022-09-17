/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:05:43 by bahn              #+#    #+#             */
/*   Updated: 2022/02/24 15:03:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	// std::cout << "AMateria Name Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& mater) {
	// std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = mater;
}

AMateria::~AMateria() {
	// std::cout << "AMateria Deconstructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& mater) {
	// std::cout << "AMateria Assignment Operator called" << std::endl;
	if (this != &mater) {
		this->type = mater.getType();
	}
	return (*this);
}

std::string const & AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}