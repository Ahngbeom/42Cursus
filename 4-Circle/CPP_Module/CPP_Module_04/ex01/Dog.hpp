/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:25:09 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:06:01 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain*	brain;
public:
	Dog();
	Dog(const Dog& dog);
	~Dog();

	Dog&	operator=(const Dog& dog);

	void	makeSound( void ) const;
	void	getIdea(const int& index) const;
};

#endif