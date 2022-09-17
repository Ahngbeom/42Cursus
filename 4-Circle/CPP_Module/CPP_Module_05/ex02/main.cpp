/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:28:17 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 15:33:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Form*	Home = new ShrubberyCreationForm("Home");
	Form*	Car = new RobotomyRequestForm("Car");
	Form*	Bane = new PresidentialPardonForm("Bane");

	Bureaucrat Me("bahn", 140);
	
	std::cout << "======================================================================================" << std::endl;
	
	{
		std::cout << "TEST #0 (Copy & Assignment)" << std::endl;
		PresidentialPardonForm*	origin = new PresidentialPardonForm("Origin");
		PresidentialPardonForm	copy(*origin);
		PresidentialPardonForm	assign = copy;

		std::cout << *origin << " (" << origin << ")" << std::endl;
		std::cout << copy << " (" << &copy << ")" << std::endl;
		std::cout << assign << " (" << &assign << ")" << std::endl;

		delete origin;
		std::cout << "======================================================================================" << std::endl;
	}

	{
		std::cout << "TEST #1 (Executer Grade : " << Me.getGrade() << ")" << std::endl;
		std::cout << "1 : \n"; Me.executeForm(*Home);
		std::cout << "2 : \n"; Me.executeForm(*Car);
		std::cout << "3 : \n"; Me.executeForm(*Bane);
		std::cout << "======================================================================================" << std::endl;
	}

	Me.incrementTheGrade(50);

	{
		std::cout << "TEST #2 (Executer Grade : " << Me.getGrade() << ")" << std::endl;
		std::cout << "1 : \n"; Me.executeForm(*Home);
		std::cout << "2 : \n"; Me.executeForm(*Car);
		std::cout << "3 : \n"; Me.executeForm(*Bane);
		std::cout << "======================================================================================" << std::endl;
	}

	Me.incrementTheGrade(50);

	{
		std::cout << "TEST #3 (Executer Grade : " << Me.getGrade() << ")" << std::endl;
		std::cout << "1 : \n"; Me.executeForm(*Home);
		std::cout << "2 : \n"; Me.executeForm(*Car);
		std::cout << "3 : \n"; Me.executeForm(*Bane);
		std::cout << "======================================================================================" << std::endl;
	}

	Me.incrementTheGrade(35);

	{
		std::cout << "TEST #4 (Executer Grade : " << Me.getGrade() << ")" << std::endl;
		std::cout << "1 : \n"; Me.executeForm(*Home);
		std::cout << "2 : \n"; Me.executeForm(*Car);
		std::cout << "3 : \n"; Me.executeForm(*Bane);
		std::cout << "======================================================================================" << std::endl;
	}
	
	delete Home;
	delete Car;
	delete Bane;

	return 0;
}
 