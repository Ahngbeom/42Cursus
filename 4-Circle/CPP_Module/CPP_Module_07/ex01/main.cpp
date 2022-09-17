/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:04:13 by bahn              #+#    #+#             */
/*   Updated: 2022/03/02 20:38:17 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	display(T& t) {
	std::cout << t << std::endl;
}

int main()
{
	int	array[] = {42, 1997, 7};
	::iter(array, sizeof(array) / sizeof(*array), display);

	std::cout << std::endl;

	std::string lyrics[] = {
		"Dancing on the edge 'bout to take it too far",
		"it's messing with my head, how i mess with your heart",
		"if you wake up in your bed alone in the dark",
		"I'm sorry gotta leave before you love me",
		"leave before you love me",
	};
	::iter(lyrics, sizeof(lyrics) / sizeof(*lyrics), display);
	
	return 0;
}
