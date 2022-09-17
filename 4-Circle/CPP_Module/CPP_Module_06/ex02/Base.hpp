/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:35:10 by bahn              #+#    #+#             */
/*   Updated: 2022/03/01 17:46:08 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	private:
		const	char	type;
	public:
		Base(const char type);
		Base(const Base& base);
		virtual ~Base();
		
		Base& operator=(const Base& base);

		char	getType() const ;
};

#endif