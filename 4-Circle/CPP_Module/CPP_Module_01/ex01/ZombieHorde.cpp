/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:43:05 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 16:00:59 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	if (N <= 0)
		return (NULL);
	std::ostringstream	oss;
	Zombie				*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		oss << ( i + 1 );
		horde[i] = Zombie(name + "_" + oss.str());
		oss.str("");
	}
	return (horde);
}
