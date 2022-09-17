/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:00:37 by bahn              #+#    #+#             */
/*   Updated: 2022/02/05 00:12:46 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 3) {
		std::cout << "Enter the arguments in the correct format." << std::endl;
		std::cout << "Usage: ./ZombieHorde [ NAME ] [ HEAD COUNT ]" << std::endl;
	}
	else {
		int					head_cnt;
		std::istringstream	iss( argv[2] );
		iss >> head_cnt;
		std::string			name( argv[1] );
		Zombie*				zb_horde = zombieHorde(head_cnt, name);
		
		if (zb_horde != NULL)
		{
			for (int i = 0; i < head_cnt; i++)
			{
				zb_horde[i].announce();
			}
			delete [] zb_horde;
		}
	}
	return (0);
} 
