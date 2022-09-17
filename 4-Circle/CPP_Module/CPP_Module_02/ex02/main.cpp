/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:55:01 by bahn              #+#    #+#             */
/*   Updated: 2022/02/09 00:20:50 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;
		
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	{
		Fixed a(3);
		Fixed const b( Fixed( 4.16f ) + Fixed( 2 ) );
		Fixed const c( Fixed( 9.55f ) - Fixed( 4 ) );
		Fixed const d( Fixed( 2.05f ) * Fixed( 8 ) );
		Fixed const e( Fixed( 30.05f ) / Fixed( 8 ) );
		
		std::cout << "a " << std::setw(16) << ": " << a << std::endl;
		std::cout << "pre-increase a " << std::setw(3) << ": " << ++a << std::endl;
		std::cout << "a " << std::setw(16) << ": " << a << std::endl;
		std::cout << "post-increase a : " << a++ << std::endl;
		std::cout << "a " << std::setw(16) << ": " << a << std::endl;
		std::cout << "pre-decrease a " << std::setw(3) << ": " << --a << std::endl;
		std::cout << "a " << std::setw(16) << ": " << a << std::endl;
		std::cout << "post-decrease a : " << a-- << std::endl;
		std::cout << "a " << std::setw(16) << ": " << a << std::endl;
		
		std::cout << std::endl;
		
		std::cout << "plus operator "<< std::setw(4) << ": " << b << std::endl;
		std::cout << "minus operator "<< std::setw(3) << ": " << c << std::endl;
		std::cout << "multi operator "<< std::setw(3) << ": " << d << std::endl;
		std::cout << "div operator "<< std::setw(5) << ": " << e << std::endl;
		
		std::cout << std::endl;
		
		std::cout << b << " < " << c << " : " << ((b < c) == 1 ? "TRUE" : "FALSE") << std::endl;
		std::cout << b << " > " << c << " : " << ((b > c) == 1 ? "TRUE" : "FALSE") << std::endl;
		std::cout << b << " <= " << c << " : " << ((b <= c) == 1 ? "TRUE" : "FALSE") << std::endl;
		std::cout << b << " >= " << c << " : " << ((b >= c) == 1 ? "TRUE" : "FALSE") << std::endl;
		Fixed b_copy( b );
		std::cout << b << " == " << b_copy << " : " << ((b == b_copy) == 1 ? "TRUE" : "FALSE") << std::endl;
		std::cout << b << " != " << b_copy << " : " << ((b != b_copy) == 1 ? "TRUE" : "FALSE") << std::endl;

		std::cout << std::endl;

		std::cout << "min of " << b << " and " << c << " : " << Fixed::min( b, c ) << std::endl;
		std::cout << "min of " << d << " and " << e << " : " << Fixed::min( d, e ) << std::endl;
		std::cout << "max of " << b << " and " << c << " : " << Fixed::max( b, c ) << std::endl;
		std::cout << "max of " << d << " and " << e << " : " << Fixed::max( d, e ) << std::endl;
	}
	return 0;
}