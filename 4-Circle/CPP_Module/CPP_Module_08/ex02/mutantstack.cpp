/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:57:04 by bahn              #+#    #+#             */
/*   Updated: 2022/03/05 16:20:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& mstack) : std::stack<T>(mstack) {
}

template <typename T>
MutantStack<T>::~MutantStack() {
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
	if (this != &other)
		this->std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return (this->c.begin());	
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return (this->c.end());	
}