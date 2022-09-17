/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:28:23 by bahn              #+#    #+#             */
/*   Updated: 2022/02/28 18:41:46 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
private:
	const	std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bureau);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& bureau);

	std::string	getName() const ;
	int			getGrade() const ;

	void	signForm(Form& form) const ;
	void	executeForm(Form const & form) const ;
	
	void	incrementTheGrade(std::size_t amount);
	void	decrementTheGrade(std::size_t amount);
};

std::ostream&	operator<<(std::ostream& ostrm, Bureaucrat const & bureau);

#endif