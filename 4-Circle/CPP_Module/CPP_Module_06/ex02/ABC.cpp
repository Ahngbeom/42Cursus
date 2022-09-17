/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:50:25 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:53:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"

/* A Class */
A::A(const char type) : Base(type)
{
}

A::A(const A& a) : Base(a)
{
}

A::~A()
{
}

A& A::operator=(const A& a)
{
	if (this != &a)
		this->Base::operator=(a);
	return (*this);
}
/* A Class End*/

/* B Class */
B::B(const char type) : Base(type)
{
}

B::B(const B& a) : Base(a)
{
}

B::~B()
{
}

B& B::operator=(const B& a)
{
	if (this != &a)
		this->Base::operator=(a);
	return (*this);
}
/* B Class End*/

/* C Class */
C::C(const char type) : Base(type)
{
}

C::C(const C& a) : Base(a)
{
}

C::~C()
{
}

C& C::operator=(const C& a)
{
	if (this != &a)
		this->Base::operator=(a);
	return (*this);
}
/* C Class End*/
