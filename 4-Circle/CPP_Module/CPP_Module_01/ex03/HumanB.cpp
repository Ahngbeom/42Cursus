/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:55:43 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 21:49:08 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _weapon(NULL), _name(name) {
}

HumanB::~HumanB() {
}

void	HumanB::setWeapon( Weapon& weapon ) {
	_weapon = &weapon;
}

void	HumanB::attack( void ) {
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}