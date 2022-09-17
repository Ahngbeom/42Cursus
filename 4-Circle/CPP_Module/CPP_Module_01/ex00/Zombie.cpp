/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:05:00 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 15:10:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "someone appeared!" << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << "<" << _name << ">";
	std::cout << " has appeared!" << std::endl;
}

Zombie::~Zombie() {
	_name.empty() ? 
		std::cout << "someone disappeared." << std::endl :
		std::cout << "<" << _name << ">" << " has disappeared." << std::endl;
	
}

void	Zombie::announce( void ) {
	_name.empty() ?
		std::cout << "<Unknown> " :
		std::cout << "<" << _name << "> ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}