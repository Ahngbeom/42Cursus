/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:43:57 by bahn              #+#    #+#             */
/*   Updated: 2022/02/05 21:29:11 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
private:
	enum	e_level {
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	std::string	arr_level[4];

	void	(Karen::*func)();

	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	Karen();
	~Karen();
	void complain( std::string level );
};

#endif