/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:35:57 by bahn              #+#    #+#             */
/*   Updated: 2022/03/02 20:38:03 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T array[], std::size_t length, void(*func)(T& t)) {
	for (std::size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

#endif