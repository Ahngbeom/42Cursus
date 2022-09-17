/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:58:59 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 15:27:45 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : \
	ClapTrap(name + "_clap_name"), ScavTrap(getName()), FragTrap(getName()), name(name)
{
	std::cout << "[DiamondTrap] Name constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	this->displayAttributes();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] Deconstructor called" << std::endl;
}

void	DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void 	DiamondTrap::whoAmI( void ) {
	std::cout << "DiamondTrap My Name is \"";
	std::cout << this->name << "\"" << std::endl;
	std::cout << "DiamondTrap My ClapTrap Name is \"";
	std::cout << ClapTrap::name << "\"" << std::endl;
}
