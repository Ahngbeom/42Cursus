/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:19 by bahn              #+#    #+#             */
/*   Updated: 2022/03/04 14:53:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	::easyfind(vec, 0);
	::easyfind(vec, 1);
	::easyfind(vec, 5);
	::easyfind(vec, 7);
	::easyfind(vec, 10);
	::easyfind(vec, 100);

	return 0;
}
