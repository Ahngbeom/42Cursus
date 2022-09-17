/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:28:17 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 16:32:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	{
		/* Copy & Assignment TEST */
		try
		{
			Form	form = Form("Form", 99, 100);
			Form	copy(form);
			Form	assign = copy;

			std::cout << form << " " << form.getSignGrade() << " <- " << &form << std::endl;
			std::cout << copy << " " << form.getSignGrade() << " <- " << &copy << std::endl;
			std::cout << assign << " " << form.getSignGrade() << " <- " << &assign << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR : " << e.what() << std::endl;
			// return (1);
		}
	}
	
	std::cout << "==================================================================" << std::endl;
	
	{
		/* When signGrade of Form is too high */
		try
		{
			Form	form = Form("Form", 0, 100);
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR : " << e.what() << std::endl;
			// return (1);
		}
	}
	
	std::cout << "==================================================================" << std::endl;
	
	{
		/* When executeGrade of Form is too low */
		try
		{
			Form	form = Form("Form", 5, 199);
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR : " << e.what() << std::endl;
			// return (1);
		}
	}
	
	std::cout << "==================================================================" << std::endl;
	
	{
		/* When grade of Bureaucrat is too high */
		try
		{
			Form	form = Form("Form", 100, 100);

			Bureaucrat aaron("Aaron", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR : " << e.what() << std::endl;
			// return (1);
		}
	}
	
	std::cout << "==================================================================" << std::endl;
	
	{
		Form	form = Form("Form", 100, 100);
		
		Bureaucrat aaron("Aaron", 1);
		Bureaucrat emile("Emile", 100);
		Bureaucrat bukayo("Bukayo", 150);
		
		aaron.signForm(form);
		emile.signForm(form);
		bukayo.signForm(form);
		
		std::cout << std::endl;

		aaron.incrementTheGrade(1);
		emile.decrementTheGrade(1);
		bukayo.incrementTheGrade(100);

		aaron.signForm(form);
		emile.signForm(form);
		bukayo.signForm(form);
	}

	return 0;
}
 