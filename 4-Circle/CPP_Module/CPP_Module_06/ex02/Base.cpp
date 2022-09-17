/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:45:43 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:56:48 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(const char type) : type(type) {
	
}

Base::Base(const Base& base) : type(base.getType()) {

}

Base::~Base() {
	
}
		
Base& Base::operator=(const Base& base) {
	if (this != &base)
		*const_cast<char*>(&this->type) = base.getType();
	return (*this);
}

char	Base::getType() const {
	return (type);
}