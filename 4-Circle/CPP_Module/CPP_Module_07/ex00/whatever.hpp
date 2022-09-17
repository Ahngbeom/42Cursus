/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:13:05 by bahn              #+#    #+#             */
/*   Updated: 2022/03/02 16:20:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T& a, T& b) {
	T	temp = a;
	
	a = b;
	b = temp;
}

template <typename T>
T&	min(T& a, T& b) {
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T&	max(T& a, T& b) {
	if (a > b)
		return (a);
	else
		return (b);
}

#endif