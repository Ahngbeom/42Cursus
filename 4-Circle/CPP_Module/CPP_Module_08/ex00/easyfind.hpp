/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:04:29 by bahn              #+#    #+#             */
/*   Updated: 2022/03/04 14:42:34 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <algorithm> // find()
# include <exception>

# ifdef __linux__
	# define _NOEXCEPT _GLIBCXX_USE_NOEXCEPT
# endif

class NotFound : public std::exception
{
private:
	std::string	msg;
public:
	NotFound();
	~NotFound() _NOEXCEPT;
	virtual const char* what() const _NOEXCEPT;
};

NotFound::NotFound() : msg("Not Found.") {
}

NotFound::~NotFound() _NOEXCEPT {
}

const char* NotFound::what() const _NOEXCEPT {
	return (msg.c_str());
}

template <typename T>
void	easyfind(T& t, int find) {
	typename T::iterator elem = std::find(t.begin(), t.end(), find);
	try
	{
		if (elem == t.end())
			throw NotFound();
		std::cout << *elem << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

#endif