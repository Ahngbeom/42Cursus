/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:13:02 by bahn              #+#    #+#             */
/*   Updated: 2022/03/02 23:52:19 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

#include "ABC.hpp"

Base * generate(void) {
	while (true) {
		switch (rand() % 3)
		{
		case 0:
			return (new A('A'));
		case 1:
			return (new B('B'));
		case 2:
			return (new C('C'));
		}
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::bad_cast &) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::bad_cast &) {}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::bad_cast &) {}
}

int main()
{
	std::srand((unsigned int)time(NULL));

	{
		std::cout << "Base Pointer TEST" << std::endl;
		
		Base*	ptr_base = generate(); 
		
		std::cout << "TYPE : " << ptr_base->getType() << std::endl;
		std::cout << "dynamic_cast : ";
		identify(ptr_base); delete ptr_base; ptr_base = generate();

		std::cout << "TYPE : " << ptr_base->getType() << std::endl;
		std::cout << "dynamic_cast : ";
		identify(ptr_base); delete ptr_base; ptr_base = generate();

		std::cout << "TYPE : " << ptr_base->getType() << std::endl;
		std::cout << "dynamic_cast : ";
		identify(ptr_base); delete ptr_base;
	}
	
	std::cout << std::endl;

	{
		std::cout << "Base Reference TEST" << std::endl;
		
		Base*	ref_base = generate();
		
		std::cout << "TYPE : " << ref_base->getType() << std::endl;
		std::cout << "dynamic_cast : ";
		identify(*ref_base); delete ref_base; ref_base = generate();
		
		std::cout << "TYPE : " << ref_base->getType() << std::endl;
		std::cout << "dynamic_cast : ";
		identify(*ref_base); delete ref_base; ref_base = generate();
		
		std::cout << "TYPE : " << ref_base->getType() << std::endl;
		std::cout << "dynamic_cast : ";
		identify(*ref_base); delete ref_base;
	}
	return 0;
}
