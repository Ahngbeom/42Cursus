/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:13:02 by bahn              #+#    #+#             */
/*   Updated: 2022/02/26 16:01:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

std::ostream&	operator<<(std::ostream& ostrm, Data &data) {
	ostrm << "[";
	ostrm << data.ch << ", ";
	ostrm << data.integerNum << ", ";
	ostrm << data.floatNum << ", ";
	ostrm << data.doubleNum;
	ostrm << "]" << std::endl;
	return (ostrm);
}

int main()
{
	Data	data('?', 19, 97.07f, 04.1);
	std::cout << "[data] : " << data;

	uintptr_t serial = serialize(&data);
	std::cout << "[data] serialized : " << serial << std::endl;

	Data	*deserial = deserialize(serial);
	std::cout << "[data] deserialized : " << *deserial;
	
	return 0;
}
