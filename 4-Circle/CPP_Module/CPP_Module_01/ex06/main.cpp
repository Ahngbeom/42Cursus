/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 00:43:47 by bahn              #+#    #+#             */
/*   Updated: 2022/02/05 14:58:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cout << "Error : Enter the arguments in the correct format." << std::endl;
		std::cout << "./karenFilter [LEVEL]" << std::endl;
	}
	else { 
		Karen	karen;

		karen.complain(argv[1]);
	}
	return 0;
}
