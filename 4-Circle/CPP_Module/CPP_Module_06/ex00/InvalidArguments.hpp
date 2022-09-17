/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidArguments.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:15:52 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:37:20 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVALID_ARGUMENTS_HPP
# define INVALID_ARGUMENTS_HPP

# include <exception>
# include <string>

# ifdef	__linux__
	# define _NOEXCEPT	_GLIBCXX_USE_NOEXCEPT
# endif

class InvalidArguments : public std::exception
{
private:
	std::string _error;
public:
	InvalidArguments();
	InvalidArguments(const InvalidArguments& inval);
	~InvalidArguments() _NOEXCEPT;
	
	InvalidArguments&	operator=(const InvalidArguments& inval);

	virtual const char*	what() const _NOEXCEPT;
};

#endif