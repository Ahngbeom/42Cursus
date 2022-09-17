/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:24:50 by bahn              #+#    #+#             */
/*   Updated: 2022/02/04 01:55:54 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : capacity() {
	std::cout << "\e[1;100m                                        \e[0m" << std::endl;
	std::cout << "\e[1;100m         \e[0m \e[33mWelcome to\e[0m\e[0m \e[32;1;5mPhone Book\e[0m \e[1;100m        \e[0m" << std::endl;
	std::cout << "\e[1;100m                                        \e[0m" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "See you again ~ " << std::endl;
}

std::size_t	PhoneBook::get_nextIndex() {
	return (contact[MAX - 1].get_id() + 1);
}

void	PhoneBook::add_contacts(void)
{
	std::string	input;
	std::size_t	i;

	if (capacity < MAX)
	{
		// contact[capacity].set_info(Index, std::to_string(capacity + 1));
		contact[capacity].set_id(capacity + 1);
		for (size_t i = FirstName; i <= DarkestSecret; i++)
		{
			std::cout << contact[capacity].display_input_field(i);
			std::getline(std::cin, input);
			contact[capacity].set_info(i - 1, input);
		}
		capacity++;
	}
	else
	{
		contact[0].~Contact();
		for (i = 0; i < MAX - 1; i++)
		{
			contact[i] = contact[i + 1];
		}
		// contact[i].set_info(Index, std::to_string(get_nextIndex()));
		contact[capacity].set_id(get_nextIndex());
		for (size_t j = FirstName; j <= DarkestSecret; j++)
		{
			std::cout << contact[i].display_input_field(j);
			std::getline(std::cin, input);
			contact[i].set_info(j - 1, input);
		}
	}
}

void	PhoneBook::search_contacts(void)
{
	std::string	command;
	std::size_t	index;

	contact[capacity].display_field();
	if (capacity == 0)
	{
		std::cout << "*** Contact is empty. ***" << std::endl;
		return ;
	}
	for (size_t i = 0; i < capacity; i++)
	{
		contact[i].get_info();
	}
	while (1)
	{
		std::cout << "[Enter the index you want to see in detail (Escape : EXIT)]" << std::endl;
		std::cout << "> ";
		// std::getline(std::cin, command);
		// if (!command.compare("EXIT") || !command.compare("exit"))
		// 	break ;
		// else if (command.empty() == true)
		// 	continue ;
		// try
		// {
		// 	index = std::stoi(command);
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << " Error : Convert Failed" << std::endl;
		// 	continue ;
		// }
		// search_index(index);
		std::cin >> index;
		try
		{
			if (std::cin.fail()) {
				throw (false);
			}
			else
				throw (true);
		}
		catch(const bool boolean)
		{
			if (boolean)
			{
				search_index(index);
				std::cin.clear();
			}
			else
			{
				std::cin.clear();
				std::getline(std::cin, command);
				if (!command.compare("EXIT") || !command.compare("exit"))
					break ;
				else if (command.empty() == true)
					continue ;
				else
					std::cout << "WARNING : Invalid Commands." << std::endl;
				continue ;
			}
		}
		
	}
}

void	PhoneBook::search_index(std::size_t index) {
	for (size_t i = 0; i < capacity; i++)
	{
		if (contact[i].get_id() == index)
		{
			std::cout << std::endl;
			std::cout << contact[i].display_input_field(Index) << contact[i].get_id() << std::endl;
			for (size_t j = FirstName; j <= DarkestSecret; j++)
			{
				std::cout << contact[i].display_input_field(j) << contact[i].get_info(j - 1) << std::endl;
			}
			std::cout << std::endl;
			return ;
		}
	}
	std::cout << "Not Found." << std::endl;
}
