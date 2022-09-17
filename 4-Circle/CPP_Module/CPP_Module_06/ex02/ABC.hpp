/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:53:00 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:54:05 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ABC_HPP
# define ABC_HPP

# include "Base.hpp"

class A : public Base
{
public:
	A(const char type);
	A(const A& a);
	~A();

	A& operator=(const A& a);
};

class B : public Base
{
public:
	B(const char type);
	B(const B& a);
	~B();

	B& operator=(const B& a);
};

class C : public Base
{
public:
	C(const char type);
	C(const C& a);
	~C();

	C& operator=(const C& a);
};

#endif