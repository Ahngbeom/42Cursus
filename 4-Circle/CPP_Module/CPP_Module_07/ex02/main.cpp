/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:06:15 by bahn              #+#    #+#             */
/*   Updated: 2022/03/03 21:44:39 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

	{
		{
			std::cout << std::endl << "[Array Elements Checking]" << std::endl;
			
			std::cout << "[numbers] " << numbers;
			std::cout << "[intArray] Array {";
			for (std::size_t i = 0; i < numbers.size(); i++) {
				if (i < 5 || i >= numbers.size() - 5)
					std::cout << mirror[i];
				else
					continue;
				if (i != numbers.size() - 1)
					std::cout << ", ";
				if (i == 4) {
					std::cout << ". . . . . ";
				}
			}
			std::cout << "}" << std::endl;
		}

		std::cout << std::endl;
		
		{
			std::cout << "[Array Copy & Assignment Checking]" << std::endl;
			
			Array<int> copy(numbers);
			Array<int> assign;
			assign = copy;

			std::cout << "[copy] " << copy;
			std::cout << "[assign] " << assign;

			copy[0] = 0;
			assign[1] = -1;
			
			std::cout << "[copy] " << copy;
			std::cout << "[assign] " << assign;
		}

		std::cout << std::endl;

		{
			std::cout << "[Array<std::string> TEST]" << std::endl;
			Array<std::string>  strArr(5);

			strArr[0] = "Always living on the run (always living on the run)";
			strArr[1] = "Never setting with the sun (never setting with the sun)";
			strArr[2] = "Our hearts have broken and they've loved (loved, loved, loved)";
			strArr[3] = "But we're still young (but we're still young)";
			strArr[4] = "And the best is yet to come";

			for (std::size_t i = 0; i < strArr.size(); i++)
			{
				std::cout << strArr[i] << std::endl;
			}
		}
	}

    delete [] mirror;//

    return 0;
}