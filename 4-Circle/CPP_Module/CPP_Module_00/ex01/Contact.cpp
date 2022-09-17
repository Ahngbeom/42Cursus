/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:49:28 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 01:50:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::field[6] = {
	"Index",
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact() {}

Contact::~Contact() {}

std::string	Contact::display_input_field(std::size_t index) {
	return (field[index] + " : ");
}

void		Contact::display_field()
{
	display_borderLine();
	std::cout << "|";
	for (size_t i = Index; i <= Nickname; i++)
	{
		std::cout << std::setw(DISPLAY_MAX_WIDTH) << std::left << field[i];
		std::cout << "|";
	}
	std::cout << std::endl;
	display_borderLine();
}

void		Contact::display_borderLine()
{
	std::cout << std::setw((DISPLAY_MAX_WIDTH + 1) * (Nickname + 1) + 1) << std::setfill('-') << "" << std::endl;
	std::cout << std::setfill(' ');
}

void	Contact::set_id(std::size_t index)
{
	id = index;
}


void	Contact::set_info(size_t index, std::string info)
{
	informations[index] = info;
}

std::size_t	Contact::get_id() {
	return (id);
}

void	Contact::get_info() {
	
	std::cout << "|" << std::left << std::setw(DISPLAY_MAX_WIDTH) << get_id();
	for (size_t i = FirstName; i <= Nickname; i++)
	{
		if (informations[i].size() >= DISPLAY_MAX_WIDTH)
			std::cout << "|" << std::left << std::setw(DISPLAY_MAX_WIDTH) << informations[i - 1].substr(0, 10).replace(10, 1, ".");
		else
			std::cout << "|" << std::left << std::setw(DISPLAY_MAX_WIDTH) << informations[i - 1];
		if (i == Nickname)
			std::cout << "|" << std::endl;
	}
	display_borderLine();
}

std::string	Contact::get_info(std::size_t index) {
	return (informations[index]);
}
