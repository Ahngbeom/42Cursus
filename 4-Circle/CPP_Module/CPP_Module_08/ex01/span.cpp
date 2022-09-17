/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:37:01 by bahn              #+#    #+#             */
/*   Updated: 2022/03/05 03:28:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "span.hpp"

Span::Span(unsigned int N) : size(N)
{
	this->vec.reserve(N);
}

Span::Span(const Span& span) {
	*this = span;
}

Span::~Span()
{
}

Span& Span::operator=(const Span& span) {
	if (this != &span) {
		this->vec = span.getVector();
		this->size = span.getSize();
	}
	return (*this);
}

Span::intVector_t Span::getVector( void ) const {
	return (vec);
}

unsigned int	Span::getSize( void ) const {
	return (size);
}

void	Span::displayElements( void ) const {
	std::cout << "[";
	for (unsigned int i = 0; i < getSize() && i < vec.size(); i++)
	{
		std::cout << vec.at(i);
		if (i != getSize() - 1)
			std::cout << " ";
	}
	std::cout << "]" << std::endl;
}

void	Span::addNumber(int num) {
	try
	{
		if (vec.size() < this->size)
			vec.push_back(num);
		else
			throw OutOfRange();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void 	Span::insertNumber(Span::intVector_iter first, Span::intVector_iter last) {
	this->vec.insert(this->vec.end(), first, last);
}

int		Span::shortestSpan( void ) {
	try
	{
		if (this->vec.size() <= 1)
			throw TooLessElements();
		std::sort(vec.begin(), vec.end(), std::less<int>());
		return (std::abs(std::minus<int>()(*(vec.begin() + 1), *(vec.begin()))));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
}

int		Span::longestSpan( void ) {
	try
	{
		if (this->vec.size() <= 1)
			throw TooLessElements();
		std::sort(vec.begin(), vec.end(), std::greater<int>());
		return (std::abs(std::minus<int>()(*vec.begin(), *(vec.end() - 1))));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (-1);
	}
}

Span::TooLessElements::TooLessElements() : msg("Too less Elements") {
	
}
Span::TooLessElements::~TooLessElements() _NOEXCEPT {
	
}
const char *Span::TooLessElements::what() const _NOEXCEPT {
	return (msg.c_str());
}

Span::OutOfRange::OutOfRange() : msg("Out of range")
{
}

Span::OutOfRange::~OutOfRange() _NOEXCEPT
{
}

const char *Span::OutOfRange::what() const _NOEXCEPT {
	return (msg.c_str());
}
