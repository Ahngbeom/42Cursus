/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:56:16 by bahn              #+#    #+#             */
/*   Updated: 2022/02/08 23:46:00 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractBits = 8;

Fixed::Fixed() : _fixedPointVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointVal = n << _fractBits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointVal = roundf(n * pow(2, _fractBits));
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed)
		this->_fixedPointVal = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return ((float)_fixedPointVal) / pow(2, _fractBits);
}

int Fixed::toInt( void ) const {
	return (_fixedPointVal >> _fractBits);
}

int	Fixed::getRawBits( void ) const {
	return (_fixedPointVal);
}

void Fixed::setRawBits( int const raw ) {
	_fixedPointVal = raw;
}

std::ostream&	operator<<(std::ostream& ostrm, const Fixed& fixed) {
	ostrm << fixed.toFloat();
	return (ostrm);
}
