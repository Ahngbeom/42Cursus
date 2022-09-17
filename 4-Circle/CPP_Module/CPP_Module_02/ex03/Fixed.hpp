/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:55:31 by bahn              #+#    #+#             */
/*   Updated: 2022/02/08 16:53:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

class Fixed
{
private:
	int					_fixedPointVal;
	static const int	_fractBits;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	Fixed(const float n);
	Fixed(const int);
	~Fixed();

	Fixed&	operator+(const Fixed& fixed);
	Fixed&	operator-(const Fixed& fixed);
	Fixed&	operator*(const Fixed& fixed);
	Fixed&	operator/(const Fixed& fixed);
	Fixed&	operator++(); // 전위 증가 연산자
	Fixed	operator++(int); // 후위 증가 연산자
	Fixed&	operator--(); // 전위 감소 연산자
	Fixed	operator--(int); // 후위 감소 연산자
	bool	operator>(const Fixed& fixed) const;
	bool	operator<(const Fixed& fixed) const;
	bool	operator>=(const Fixed& fixed) const;
	bool	operator<=(const Fixed& fixed) const;
	bool	operator==(const Fixed& fixed) const;
	bool	operator!=(const Fixed& fixed) const;
	
	static	const Fixed&	min(const Fixed& fixed_1, const Fixed& fixed_2);
	static	const Fixed&	max(const Fixed& fixed_1, const Fixed& fixed_2);

	float toFloat( void ) const;
	int toInt( void ) const;
	int	getRawBits( void ) const ;
	void setRawBits( int const raw );
};

std::ostream&	operator<<(std::ostream& ostrm, const Fixed& fixed);

#endif