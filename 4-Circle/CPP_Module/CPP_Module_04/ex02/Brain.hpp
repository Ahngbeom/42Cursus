/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:51:47 by bahn              #+#    #+#             */
/*   Updated: 2022/02/23 23:49:54 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <fstream>
# include <string>

# define IDEAS_MAX 100

class Brain
{
private:
	std::string	ideas[IDEAS_MAX];
public:
	Brain();
	Brain(const Brain& brain);
	~Brain();
	
	Brain& operator=(const Brain& brain);

	std::string	comeToIdea(const int& index) const;
};

#endif