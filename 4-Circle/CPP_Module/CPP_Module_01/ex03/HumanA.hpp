/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:24:45 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 21:27:53 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	Weapon&		_weapon;
	std::string	_name;
public:
	HumanA( std::string name, Weapon& weapon);
	~HumanA();
	void	attack( void );
};

#endif