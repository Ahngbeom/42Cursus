/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:13:58 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 14:09:00 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "[ScavTrap - " << name << "] Name constructor called" << std::endl;
	this->displayAttributes();
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap - " << name << "] Deconstructor called" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap < " << name << " > have entered in Gate keeper mode" << std::endl;
	energyPoints -= 5;
}

void	ScavTrap::attack(std::string const & target) {
	std::cout << "ScavTrap < " << this->name << \
				" > attack < " << target << \
				" >, causing < " << this->attackDamage << " > points of damage!" \
				<< std::endl;
}
