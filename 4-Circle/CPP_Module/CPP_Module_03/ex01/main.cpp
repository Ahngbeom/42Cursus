/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:52:33 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 14:11:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	clap("CLAP");
	ScavTrap	scav("SCAV");

	clap.attack("SCAV");
	scav.takeDamage(0);
	scav.guardGate();
	
	scav.attack("CLAP");
	clap.takeDamage(20);
	scav.ClapTrap::attack("CLAP");
	clap.takeDamage(20);
	// clap.guardGate();

	clap.displayAttributes();
	scav.displayAttributes();

	clap.beRepaired(100);
	clap.displayAttributes();

	{
		ClapTrap	clone(scav);

		std::cout << &clone << std::endl;
		std::cout << &scav << std::endl;

		clone.displayAttributes();
	}

	{
		ClapTrap	clone(clap);

		std::cout << &clone << std::endl;
		std::cout << &clap << std::endl;

		clone.displayAttributes();
	}
	return 0;
}
