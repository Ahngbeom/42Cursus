/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:28:23 by bahn              #+#    #+#             */
/*   Updated: 2022/02/28 00:56:32 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

# ifdef __linux__
	# define _NOEXCEPT _GLIBCXX_NOTHROW
# endif

class Bureaucrat
{
private:
	const	std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bureau);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat & bureau);

	const std::string	getName() const ;
	int					getGrade() const ;

	void	incrementTheGrade(std::size_t amount);
	void	decrementTheGrade(std::size_t amount);

	class GradeTooHighException : public std::exception {
		private:
			std::string	_error;
		public:
			GradeTooHighException(std::string error);
			~GradeTooHighException() _NOEXCEPT;
			virtual const char* what() const _NOEXCEPT;
	};
	
	class GradeTooLowException : public std::exception {
		private:
			std::string	_error;
		public:
			GradeTooLowException(std::string error);
			~GradeTooLowException() _NOEXCEPT;
			virtual const char* what() const _NOEXCEPT;
	};
	
};

std::ostream&	operator<<(std::ostream& ostrm, Bureaucrat& bureau);

#endif