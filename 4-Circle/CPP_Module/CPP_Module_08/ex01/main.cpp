/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:19 by bahn              #+#    #+#             */
/*   Updated: 2022/03/05 16:40:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	Span	sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << std::endl;

	{
		// Deep copy TEST
		std::vector<int> v(5, 5);
		std::vector<int> cp(v);
		std::vector<int> assign;

		assign = cp;

		cp.at(0) = 0;
		assign.at(4) = 0;
		
		std::cout << "v [ ";
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v.at(i) << " ";
		}
		std::cout << "]\ncopy [ ";
		for (size_t i = 0; i < cp.size(); i++)
		{
			std::cout << cp.at(i) << " ";
		}
		std::cout << "]\nassign [ ";
		for (size_t i = 0; i < assign.size(); i++)
		{
			std::cout << assign.at(i) << " ";
		}
		std::cout << "]" << std::endl;
	}

	std::cout << std::endl;
	
	{
		// Try inserting out of vector range.
		sp.addNumber(100);
	}
	
	std::cout << std::endl;

	{
		// If vector is empty or ones
		Span	empty(0);

		empty.shortestSpan();
		empty.longestSpan();

		Span	one(1);

		one.addNumber(42);

		one.shortestSpan();
		one.longestSpan();
	}

	std::cout << std::endl;

	{
		// Size 10000 vector
		Span	sp10000 = Span(10000);
		std::vector<int> raw;
		for (int i = -5000; i < 5000; i++)
		{
			raw.push_back(i);
		}

		sp10000.insertNumber(raw.begin(), raw.end());
		
		std::cout << sp10000.shortestSpan() << std::endl;
		std::cout << sp10000.longestSpan() << std::endl;
	}

	return 0;
}
