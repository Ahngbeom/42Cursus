/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:48:37 by bahn              #+#    #+#             */
/*   Updated: 2022/02/26 15:06:01 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct Data
{
	Data(char ch, int integerNum, float floatNum, double doubleNum)
	 : ch(ch), integerNum(integerNum), floatNum(floatNum), doubleNum(doubleNum) {}
	char	ch;
	int		integerNum;
	float	floatNum;
	double	doubleNum;
};

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

std::ostream&	operator<<(std::ostream& ostrm, Data &data);

#endif