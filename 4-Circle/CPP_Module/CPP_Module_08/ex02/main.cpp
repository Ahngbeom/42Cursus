/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:19 by bahn              #+#    #+#             */
/*   Updated: 2022/03/05 16:09:10 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Mutant Stack Top: " << mstack.top() << std::endl;

	mstack.pop();
	
	std::cout << "Mutant Stack Top: " << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(6);
	mstack.push(737);
	mstack.push(0);

	std::cout << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	mstack.pop();

	std::cout << std::endl;

	std::stack<int>	s(mstack);
	
	std::cout << "Stack Top: " << mstack.top() << std::endl;

	std::cout << std::endl;

	{
		/* Copy & Assignment TEST */
		MutantStack<int>	cp(mstack);
		MutantStack<int>	assign;
		
		cp.push(999);
		assign = cp;
		assign.pop();
		
		it = mstack.begin();
		std::cout << "mstack [ ";
		while (it != ite)
			std::cout << *(it++) << " ";
		std::cout << "]" << std::endl;

		it = cp.begin();
		ite = cp.end();
		std::cout << "cp [ ";
		while (it != ite)
			std::cout << *(it++) << " ";
		std::cout << "]" << std::endl;

		it = assign.begin();
		ite = assign.end();
		std::cout << "assign [ ";
		while (it != ite)
			std::cout << *(it++) << " ";
		std::cout << "]" << std::endl;
	}


	return 0;
}
