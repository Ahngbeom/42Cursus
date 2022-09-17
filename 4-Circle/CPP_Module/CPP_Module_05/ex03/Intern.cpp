/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:40:01 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:14:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string	Intern::forms[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern()
{
}

Intern::Intern(const Intern& intern)
{
	*this = intern;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	return (*this);
}

Form*	Intern::makeForm(std::string const & targetForm, std::string const & formName) {
	size_t 		i;
	for (i = 0; i < 3; i++)
	{
		if (!targetForm.compare(forms[i]))
			break ;
	}
	
	try
	{
		switch (i)
		{
		case 0:
			std::cout << "Intern creates <ShrubberyCreationForm>" << std::endl;
			return (new ShrubberyCreationForm(formName));
		case 1:
			std::cout << "Intern creates <RobotomyRequestForm>" << std::endl;
			return (new RobotomyRequestForm(formName));
		case 2:
			std::cout << "Intern creates <PresidentialPardonForm>" << std::endl;
			return (new PresidentialPardonForm(formName));
		default:
			throw NotMatchTheForm();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}

Intern::NotMatchTheForm::NotMatchTheForm()
 : _error("Does not match the Form.")
{
}

Intern::NotMatchTheForm::~NotMatchTheForm() _NOEXCEPT {
	
}

const char*	Intern::NotMatchTheForm::what() const _NOEXCEPT {
	return (_error.c_str());
}
