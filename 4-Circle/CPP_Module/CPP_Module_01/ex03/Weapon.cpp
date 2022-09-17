/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:24:45 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 21:25:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string& type ) : _type(type) {
}

Weapon::~Weapon() {
}

void	Weapon::setType( const std::string& type ) {
	_type = type;
}
const	std::string&	Weapon::getType( void ) const {
	return (_type);
}
