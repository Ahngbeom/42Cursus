/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:25:09 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:58:22 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	brain;
public:
	Cat();
	Cat(const Cat& cat);
	~Cat();
	
	Cat&	operator=(const Cat& cat);

	void	makeSound( void ) const;
	void	getIdea(const int& index) const;
};

#endif