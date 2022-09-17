/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:28:17 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:21:42 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Form* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Alice");
	Form* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	Form* presidential = someRandomIntern.makeForm("presidential pardon", "Chris");
	
	Bureaucrat me("bahn", 140);

	std::cout << "======================================================================================" << std::endl;
	{	
		std::cout << "TEST #0 (Copy & Assignment)" << std::endl;
		Intern cloneCopy(someRandomIntern);
		Intern cloneAssign = cloneCopy;

		std::cout << &someRandomIntern << std::endl;
		std::cout << &cloneCopy << std::endl;
		std::cout << &cloneAssign << std::endl;
		std::cout << "======================================================================================" << std::endl;
	}
	
	{	
		std::cout << "TEST #1 (Executer Grade : " << me.getGrade() << ")" << std::endl;
		me.executeForm(*shrubbery);
		me.executeForm(*robotomy);
		me.executeForm(*presidential);
		std::cout << "======================================================================================" << std::endl;
	}
	
	me.incrementTheGrade(50);
	{
		std::cout << "TEST #2 (Executer Grade : " << me.getGrade() << ")" << std::endl;
		me.executeForm(*shrubbery);
		me.executeForm(*robotomy);
		me.executeForm(*presidential);
		std::cout << "======================================================================================" << std::endl;
	}

	me.incrementTheGrade(50);
	{
		std::cout << "TEST #3 (Executer Grade : " << me.getGrade() << ")" << std::endl;
		me.executeForm(*shrubbery);
		me.executeForm(*robotomy);
		me.executeForm(*presidential);
		std::cout << "======================================================================================" << std::endl;
	}

	me.incrementTheGrade(35);
	{
		std::cout << "TEST #3 (Executer Grade : " << me.getGrade() << ")" << std::endl;
		me.executeForm(*shrubbery);
		me.executeForm(*robotomy);
		me.executeForm(*presidential);
		std::cout << "======================================================================================" << std::endl;
	}

	delete shrubbery;
	delete robotomy;
	delete presidential;

	return 0;
}
 