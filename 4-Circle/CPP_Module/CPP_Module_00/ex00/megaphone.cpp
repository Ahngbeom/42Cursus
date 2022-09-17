/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:24:53 by bahn              #+#    #+#             */
/*   Updated: 2022/02/03 02:13:41 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#define NO_ARGU "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

static void	str_upper(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{	
		if (isalpha(str[i]) && islower(str[i]))
			std::cout << (char)toupper(str[i]);
		else
			std::cout << str[i];
	}
}

int main(int argc, char const *argv[])
{
	int	i;

	if (argc == 1)
	{	
		std::cout << NO_ARGU << std::endl;
		return (0);
	}
	i = 0;
	while (argv[++i] != NULL)
	{
		str_upper(argv[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
