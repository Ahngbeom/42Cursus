/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:51:45 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:50:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Constructor called" << std::endl;
	
	std::ifstream 	f_ideas;
	std::string		idea;
	
	f_ideas.open("Ideas.txt");
	for (size_t i = 0; i < IDEAS_MAX; i++)
	{
		std::getline(f_ideas, idea);
		ideas[i] = idea;
	}
}

Brain::Brain(const Brain& brain) {
	std::cout << "[Brain] Copy Constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "[Brain] Deconstructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain) {
	std::cout << "[Brain] Assignment Operator called" << std::endl;
	if (this != &brain) {
		for (size_t i = 0; i < IDEAS_MAX; i++)
		{
			this->ideas[i] = brain.ideas[i];
		}
	}
	return (*this);
}

std::string	Brain::comeToIdea(const int& index) const {
	if (!ideas[index].empty())
		return (ideas[index]);
	else
		return ("...........");
}
