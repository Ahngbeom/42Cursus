/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:31:23 by bahn              #+#    #+#             */
/*   Updated: 2022/03/05 16:32:32 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <exception>

# ifdef __linux__
	# define _NOEXCEPT _GLIBCXX_USE_NOEXCEPT
# endif

class Span
{
public:
	typedef std::vector<int> intVector_t;
	typedef std::vector<int>::iterator intVector_iter;

	Span(unsigned int N);
	Span(const Span& span);
	~Span();

	Span& operator=(const Span& span);

	intVector_t		getVector( void ) const ;
	unsigned int	getSize( void ) const ;

	void	displayElements( void ) const ;

	void	addNumber(int num);
	
	void 	insertNumber(intVector_iter first, intVector_iter last);
	
	int		shortestSpan( void );
	int		longestSpan( void );

	class TooLessElements : public std::exception
	{
	private:
		std::string	msg;
	public:
		TooLessElements();
		~TooLessElements() _NOEXCEPT;
		virtual const char *what() const _NOEXCEPT;
	};

	class OutOfRange : public std::exception
	{
	private:
		std::string	msg;
	public:
		OutOfRange();
		~OutOfRange() _NOEXCEPT;
		virtual const char *what() const _NOEXCEPT;
	};
	
private:
	intVector_t	vec;
	unsigned int	size;
};

#endif