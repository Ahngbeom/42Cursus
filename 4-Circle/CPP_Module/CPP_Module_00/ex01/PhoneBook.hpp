/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:25:20 by bahn              #+#    #+#             */
/*   Updated: 2022/02/03 01:36:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX		8

class	PhoneBook
{
private:
	Contact			contact[MAX];
	std::size_t		capacity;

public:
	PhoneBook();
	~PhoneBook();
	std::size_t	get_nextIndex();
	void		add_contacts(void);
	void		search_contacts(void);
	void		search_index(std::size_t index);
};

#endif