/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:09:22 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 16:42:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

# include "Form.hpp"
# include "ASCII_ART.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
private:
	
public:
	RobotomyRequestForm(std::string const & target);
	RobotomyRequestForm(const RobotomyRequestForm& form);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& form);

	virtual void	execute(Bureaucrat const & executer) const ;
};

#endif