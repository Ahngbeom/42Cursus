/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:54:26 by bahn              #+#    #+#             */
/*   Updated: 2022/02/03 01:00:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : _weapon(weapon), _name(name) {
}

HumanA::~HumanA() {
}

void	HumanA::attack( void ) {
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
