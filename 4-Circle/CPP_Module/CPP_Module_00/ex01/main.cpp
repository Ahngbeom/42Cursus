/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 00:50:19 by bahn              #+#    #+#             */
/*   Updated: 2022/01/31 21:33:40 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	pb;
	std::string command;

	while (1)
	{
		std::cout << "[Available Commands : ADD, SEARCH, EXIT]" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
			break ;
		else if (command == "ADD" || command == "add")
			pb.add_contacts();
		else if (command == "SEARCH" || command == "search")
			pb.search_contacts();
		else
			std::cout << "WARNING : Invalid Commands." << std::endl;
	}
	return (0);
}