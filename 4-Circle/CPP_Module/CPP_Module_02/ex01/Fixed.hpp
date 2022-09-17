/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:55:31 by bahn              #+#    #+#             */
/*   Updated: 2022/02/07 18:04:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
	Fixed&	operator=(const Fixed& fixed);
	~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;
	int	getRawBits( void ) const ;
	void setRawBits( int const raw );
};

std::ostream&	operator<<(std::ostream& ostrm, const Fixed& fixed);

#endif