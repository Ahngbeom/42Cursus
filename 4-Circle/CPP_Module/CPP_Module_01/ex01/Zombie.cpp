/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:05:00 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 16:01:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << " Default Constructor Call " << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << "<" << _name << ">";
	std::cout << " has appeared !" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "<" << _name << ">";
	std::cout << " has disappeared !" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << "<" << _name << "> ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}