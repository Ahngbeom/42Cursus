/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:30:47 by bahn              #+#    #+#             */
/*   Updated: 2022/02/28 01:09:32 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : \
	_name(name), _grade(grade)
{
	try
	{
		std::cout << "[Bureaucrat] Name & Grade constructor called ";
		if (_grade > 150)
			throw GradeTooLowException("Grade too lowest.");
		else if (_grade < 1)
			throw GradeTooHighException("Grade too high.");
		else 
			std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureau) : _name(bureau.getName()), _grade(bureau.getGrade()) {
	std::cout << "[Bureaucrat] Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Deconstructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureau) {
	std::cout << "[Bureaucrat] Assignment Operator called" << std::endl;
	if (this != &bureau) {
		*const_cast<std::string*>(&this->_name) = bureau.getName();
		this->_grade = bureau.getGrade();
	}
	return (*this);
}

const std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementTheGrade(std::size_t amount) {
	try
	{
		std::cout << getName() << ", promote!!! ";
		_grade -= amount;
		if (_grade > 150)
			throw GradeTooLowException("Grade too low.");
		else if (_grade < 1)
			throw GradeTooHighException("Grade too high.");
		else
			std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
	
void	Bureaucrat::decrementTheGrade(std::size_t amount) {
	try
	{
		std::cout << getName() << ", demote... ";
		_grade += amount;
		if (_grade > 150)
			throw GradeTooLowException("Grade too low.");
		else if (_grade < 1)
			throw GradeTooHighException("Grade too high.");
		else
			std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string error) : _error(error) {
	std::cout << "(GradeTooHighException : ";
	// std::cout << "[GradeTooHighException] Constructor called" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {
	std::cout << ")" << std::endl;
	// std::cout << "[GradeTooHighException] Deconstructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
	return (_error.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string error) : _error(error) {
	std::cout << "(GradeTooLowException : ";
	// std::cout << "[GradeTooLowException] Constructor called" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {
	std::cout << ")" << std::endl;
	// std::cout << "[GradeTooLowException] Deconstructor called" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
	return (_error.c_str());
}

std::ostream&	operator<<(std::ostream& ostrm, Bureaucrat& bureau) {
	try
	{
		ostrm << "<" << bureau.getName() << ">, ";
		ostrm << "bureaucrat grade <" << bureau.getGrade() << "> ";
		if (bureau.getGrade() > 150)
			throw Bureaucrat::GradeTooLowException("Grade too low.");
		else if (bureau.getGrade() < 1)
			throw Bureaucrat::GradeTooHighException("Grade too high.");
	}
	catch(const std::exception& e)
	{
		ostrm << e.what();
	}
	return (ostrm);
}
