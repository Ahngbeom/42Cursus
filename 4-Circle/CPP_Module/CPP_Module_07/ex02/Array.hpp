/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:45:23 by bahn              #+#    #+#             */
/*   Updated: 2022/03/03 22:21:10 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <ctime>
# include <cstring>

# ifdef	__linux__
	# define _NOEXCEPT _GLIBCXX_USE_NOEXCEPT
# endif

template <typename T>
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int size);
	Array(const Array<T>& array);
	~Array();

	Array<T>&	operator=(const Array<T>& other);

	T&	operator[](int index);
	T&	operator[](int index) const;

	unsigned int	size( void ) const;

	class IndexOutOfBounds : public std::exception
	{
	private:
		std::string	msg;
	public:
		IndexOutOfBounds();
		~IndexOutOfBounds() _NOEXCEPT;
		virtual const char* what() const _NOEXCEPT;
	};
};


template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {
	// std::cout << "Default" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {
	
};

template <typename T>
Array<T>::Array(const Array<T>& array) {
	// std::cout << "Copy" << std::endl;
	_size = array.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	if (_size != 0)
		delete [] _array;
};

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other) {
	// std::cout << "Assignment" << std::endl;
	if (this != &other) {
		delete [] _array;
		_size = other.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = other[i];
		}
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](int index) {
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw IndexOutOfBounds();
	return (_array[index]);
};

template <typename T>
T&	Array<T>::operator[](int index) const {
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw IndexOutOfBounds();
	return (_array[index]);
};

template <typename T>
unsigned int	Array<T>::size( void ) const {
	return (_size);
}

template <typename T>
Array<T>::IndexOutOfBounds::IndexOutOfBounds()
{
	msg = "Index out of bounds.";
}

template <typename T>	
Array<T>::IndexOutOfBounds::~IndexOutOfBounds() _NOEXCEPT
{
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const _NOEXCEPT
{
	return (msg.c_str());
}

template <typename T>
std::ostream&	operator<<(std::ostream& ostrm, Array<T>& array) {
	ostrm << "Array {";
	for (unsigned i = 0; i < array.size(); i++)
	{
		if (i < 5 || i >= array.size() - 5)
			ostrm << array[i];
		else
			continue;
		if (i != array.size() - 1)
			ostrm << ", ";
		if (i == 4) {
			ostrm << ". . . . . ";
		}
	}
	ostrm << "}" << std::endl;
	return (ostrm);
}

#endif