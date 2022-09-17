/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:52:33 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 15:32:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	ClapTrap	clap("CLAP"); std::cout << std::endl;
	ScavTrap	scav("SCAV"); std::cout << std::endl;
	FragTrap	frag("FRAG"); std::cout << std::endl;
	DiamondTrap	diamond("DIAMOND"); std::cout << std::endl;

	std::cout << "========================= FIGHT ============================" << std::endl;

	scav.attack("CLAP");
	clap.takeDamage(scav.getAttackDamage());
	
	frag.highFivesGuys();

	scav.attack("FRAG");
	frag.takeDamage(scav.getAttackDamage());

	frag.attack("SCAV");
	scav.takeDamage(frag.getAttackDamage());

	scav.guardGate();

	diamond.attack("FRAG");
	frag.takeDamage(diamond.getAttackDamage());
	diamond.attack("SCAV");
	scav.takeDamage(diamond.getAttackDamage());
	
	diamond.whoAmI();
	std::cout << "========================== END =============================" << std::endl;

	clap.displayAttributes();
	scav.displayAttributes();
	frag.displayAttributes();
	diamond.displayAttributes();
	return 0;
}
