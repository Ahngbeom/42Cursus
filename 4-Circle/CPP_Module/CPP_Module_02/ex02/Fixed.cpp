/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:56:16 by bahn              #+#    #+#             */
/*   Updated: 2022/02/09 00:33:27 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractBits = 8;

/********************************
	CONSTRUCTOR & DECONSTRUCTOR
********************************/
Fixed::Fixed() : _fixedPointVal(0) {
}

Fixed::Fixed(const Fixed& fixed) : _fixedPointVal(0) {
	*this = fixed;
}

Fixed::Fixed(const int n) : \
	_fixedPointVal(n << _fractBits) {
}

Fixed::Fixed(const float n) : \
	_fixedPointVal(roundf(n * pow(2, _fractBits))) {
}

Fixed::~Fixed() {
}


/********************************
 			OPERATOR
********************************/

/*		Assignment			*/
Fixed& Fixed::operator=(const Fixed& fixed) {
	if (this != &fixed)
		this->_fixedPointVal = fixed.getRawBits();
	return (*this);
}
/*		Assignment	End		*/


/*		Arithmetic		*/
Fixed&	Fixed::operator+(const Fixed& fixed) {
	_fixedPointVal += fixed.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator-(const Fixed& fixed) {
	_fixedPointVal -= fixed.getRawBits();
	return (*this);
}

Fixed& Fixed::operator*(const Fixed& fixed) {
	float	n;

	n = this->toFloat() * fixed.toFloat();
	*this = Fixed(n);
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed& fixed) {
	float	n;

	n = this->toFloat() / fixed.toFloat();
	*this = Fixed(n);
	return (*this);
}
/*		Arithmetic	End		*/


/*		Increase & Decrease		*/
Fixed&	Fixed::operator++() {
	this->setRawBits(getRawBits() + 1);
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed&	Fixed::operator--() {
	this->setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}
/*		Increase & Decrease	End		*/


/*		Comparison		*/
bool	Fixed::operator>(const Fixed& fixed) const {
	return ( this->getRawBits() > fixed.getRawBits() );
}
bool	Fixed::operator<(const Fixed& fixed) const {
	return ( this->getRawBits() < fixed.getRawBits() );
}
bool	Fixed::operator>=(const Fixed& fixed) const {
	return ( this->getRawBits() >= fixed.getRawBits() );
}
bool	Fixed::operator<=(const Fixed& fixed) const {
	return ( this->getRawBits() <= fixed.getRawBits() );
}
bool	Fixed::operator==(const Fixed& fixed) const {
	return ( this->getRawBits() == fixed.getRawBits() );
}
bool	Fixed::operator!=(const Fixed& fixed) const {
	return ( this->getRawBits() != fixed.getRawBits() );
}
/*		Comparison	End		*/


/*		Output		*/
std::ostream&	operator<<(std::ostream& ostrm, const Fixed& fixed) {
	ostrm << fixed.toFloat();
	return (ostrm);
}
/*		Output	End		*/


/********************************
 			FUNCTION
********************************/
const	Fixed&	Fixed::min(const Fixed& fixed_1, const Fixed& fixed_2) {
	if (fixed_1 > fixed_2)
		return (fixed_2);
	else
		return (fixed_1);
}

const	Fixed&	Fixed::max(const Fixed& fixed_1, const Fixed& fixed_2) {
	if (fixed_1 >= fixed_2)
		return (fixed_1);
	else
		return (fixed_2);
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
