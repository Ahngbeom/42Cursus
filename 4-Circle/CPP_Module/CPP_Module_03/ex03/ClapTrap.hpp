/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:52:50 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 15:03:43 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
	std::string	name;	
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& ct);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& ct);

	void		displayAttributes( void );
	std::string	getName( void );
	int			getHitPoints( void );
	int			getEnergyPoints( void );
	int			getAttackDamage( void );

	void 		attack(std::string const & target);
	void 		takeDamage(unsigned int amount);
	void 		beRepaired(unsigned int amount);
};

#endif