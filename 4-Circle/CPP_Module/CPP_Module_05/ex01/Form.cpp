/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:46:22 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 16:19:36 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int signGrade, const int executeGrade) 
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1) {
		if (_signGrade < 1 && _executeGrade < 1)
			throw GradeTooHighException("Standard grade required for execution and signing is too high.");
		else if (_signGrade < 1)
			throw GradeTooHighException("Standard grade required for signing is too high.");
		else
			throw GradeTooHighException("Standard grade required for execution is too high.");
	}
	else if (_signGrade > 150 || _executeGrade > 150) {
		if (_signGrade > 150 && _executeGrade > 150)
			throw GradeTooLowException("Standard grade required for execution and signing is too low.");
		else if (_signGrade > 150)
			throw GradeTooLowException("Standard grade required for signing is too low.");
		else
			throw GradeTooLowException("Standard grade required for execution is too low.");
	}
}

Form::Form(const Form& form) 
	: _name(form.getName()), _signed(form.getSigned()), _signGrade(form.getSignGrade()), _executeGrade(form.getExecuteGrade()) {
	if (_signGrade < 1 || _executeGrade < 1) {
		if (_signGrade < 1 && _executeGrade < 1)
			throw GradeTooHighException("Standard grade required for execution and signing is too high.");
		else if (_signGrade < 1)
			throw GradeTooHighException("Standard grade required for signing is too high.");
		else
			throw GradeTooHighException("Standard grade required for execution is too high.");
	}
	else if (_signGrade > 150 || _executeGrade > 150) {
		if (_signGrade > 150 && _executeGrade > 150)
			throw GradeTooLowException("Standard grade required for execution and signing is too low.");
		else if (_signGrade > 150)
			throw GradeTooLowException("Standard grade required for signing is too low.");
		else
			throw GradeTooLowException("Standard grade required for execution is too low.");
	}
}

Form::~Form()
{
}

Form&	Form::operator=(const Form& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->_name) = form.getName();
		this->_signed = form.getSigned();
		*const_cast<int*>(&this->_signGrade) = form.getSignGrade();
		*const_cast<int*>(&this->_executeGrade) = form.getExecuteGrade();
		
		if (_signGrade < 1 || _executeGrade < 1) {
			if (_signGrade < 1 && _executeGrade < 1)
				throw GradeTooHighException("Standard grade required for execution and signing is too high.");
			else if (_signGrade < 1)
				throw GradeTooHighException("Standard grade required for signing is too high.");
			else
				throw GradeTooHighException("Standard grade required for execution is too high.");
		}
		else if (_signGrade > 150 || _executeGrade > 150) {
			if (_signGrade > 150 && _executeGrade > 150)
				throw GradeTooLowException("Standard grade required for execution and signing is too low.");
			else if (_signGrade > 150)
				throw GradeTooLowException("Standard grade required for signing is too low.");
			else
				throw GradeTooLowException("Standard grade required for execution is too low.");
		}
	}
	return (*this);
}

std::string	Form::getName( void ) const {
	return (_name);
}

int	Form::getSignGrade( void ) const {
	return (_signGrade);
}

int	Form::getExecuteGrade( void ) const {
	return (_executeGrade);
}

bool	Form::getSigned( void ) const  {
	return (_signed);
}

void	Form::beSigned(Bureaucrat& bureau) {
	_signed = false;
	if (bureau.getGrade() <= getSignGrade() && bureau.getGrade() >= 1)
		_signed = true;
	else if (bureau.getGrade() < 1)
		throw GradeTooHighException("A grade required for signing is too high.");
	else
		throw GradeTooLowException("A grade required for signing is too low.");
}

Form::GradeTooHighException::GradeTooHighException(std::string error) : _error(error) {

}

Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {
	
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT {
	return (_error.c_str());
}


Form::GradeTooLowException::GradeTooLowException(std::string error) : _error(error) {
	
}
		
Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {
	
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT {
	return (_error.c_str());
}

std::ostream&	operator<<(std::ostream& ostrm, Form& form) {
	ostrm << "<" + form.getName() + ">";
	return (ostrm);
}
