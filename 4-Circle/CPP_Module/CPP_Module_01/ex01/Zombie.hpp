/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:04:46 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 16:21:09 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie( std::string name );
	~Zombie();

	void	announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif