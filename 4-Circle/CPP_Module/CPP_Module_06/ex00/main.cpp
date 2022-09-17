/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:13:02 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 21:40:47 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // showpos
#include <cstdlib> // strtod
#include <cmath> // isnan, isinf, fmodf
#include <cctype> // isprint
#include <limits> // numeric_limits

#include "InvalidArguments.hpp"

void	outputCharacter(double& num) {
	try
	{
		std::cout << "char: ";

		if (std::isnan(num) || std::isinf(num) \
			|| num < (double)std::numeric_limits<unsigned char>::min() \
			|| num > (double)std::numeric_limits<unsigned char>::max())
			throw "impossible";
		else if (!std::isprint(num))
			throw "Non displayable";
		else 
			std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	}
	catch(char const* message)
	{
		std::cerr << message << std::endl;;
	}
}

void	outputInteger(double& num) {
	try
	{
		std::cout << "int: ";
		if (std::isnan(num) || std::isinf(num) \
			|| num < std::numeric_limits<int>::min() \
			|| num > std::numeric_limits<int>::max())		
			throw "impossible";
		else	
			std::cout << static_cast<int>(num) << std::endl;
	}
	catch(char const* message)
	{
		std::cerr << message << std::endl;
	}
}

void	outputFloat(double& num) {
	try
	{
		std::cout << "float: ";
		if (std::isinf(static_cast<float>(num))) {
			std::cout << std::showpos;
		}
		if (fmodf(static_cast<float>(num), 1.0) == 0) {
			std::cout.precision(1);
		}
		std::cout << static_cast<float>(num) << "f" << std::endl;
	}
	catch(char const* message)
	{
		std::cerr << message << std::endl;
	}
}

void	outputDouble(double& num) {
	try
	{
		std::cout << "double: ";
		if (std::isinf(static_cast<float>(num))) {
			std::cout << std::showpos;
		}
		if (fmod(static_cast<double>(num), 1.0) == 0) {
			std::cout.precision(1);
		}
		std::cout << static_cast<double>(num) << std::endl;
	}
	catch(char const* message)
	{
		std::cerr << message << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	try
	{
		if (argc != 2)
			throw InvalidArguments();
		
		double	num = std::strtod(argv[1], NULL);

		std::cout << std::fixed;

		outputCharacter(num);
		outputInteger(num);
		outputFloat(num);
		outputDouble(num);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}