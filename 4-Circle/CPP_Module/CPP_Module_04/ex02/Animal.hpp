/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:23:20 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:46:35 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& animal);
	virtual ~Animal();
	
	Animal&	operator=(const Animal& animal);
	
	std::string	getType( void ) const;

	virtual void	makeSound( void ) const = 0;
	virtual void	getIdea(const int& index) const = 0;
};

#endif