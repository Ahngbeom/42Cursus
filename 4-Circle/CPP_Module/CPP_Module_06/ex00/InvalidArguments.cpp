/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidArguments.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:17:34 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:39:01 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InvalidArguments.hpp"

InvalidArguments::InvalidArguments() : _error("Invalid Arguments.")
{
}

InvalidArguments::InvalidArguments(const InvalidArguments& inval) : std::exception(inval)
{
}

InvalidArguments::~InvalidArguments() _NOEXCEPT
{
}

InvalidArguments&	InvalidArguments::operator=(const InvalidArguments& inval)
{
	if (this != &inval) {
		this->std::exception::operator=(inval);
	}
	return (*this);
}

const char*	InvalidArguments::what() const _NOEXCEPT {
	return (_error.c_str());
}
