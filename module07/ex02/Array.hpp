#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
template <typename T>

class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Array(void) : _array(new T[0]),_size(0)
		{
			std::cout << "Default constructor called" << std::endl;
		}
		Array(unsigned int n): _array(new T[n]), _size(n)
		{
			std::cout << "Constructor with size called" << std::endl;
		}
		Array(Array const &src): _array(new T[src._size]), _size(src._size)
		{
			std::cout << "Copy constructor called" << std::endl;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		~Array(void)
		{
			std::cout << "Destructor called" << std::endl;
			delete [] _array;
		}
		Array &operator=(Array const &src)
		{
			std::cout << "Assignment operator called" << std::endl;
			if (this != &src)
			{
				delete [] _array;
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			return *this;
		}
		T &operator[](unsigned int i)
		{
			if (i >= _size || _array == NULL)
				throw Array<T>::OutOfboundsException();
			return _array[i];
		}
		unsigned int size(void) const {return _size;}
		class OutOfboundsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

template <typename T>

const char *Array<T>::OutOfboundsException::what() const throw()
{
	return "Out of bounds";
}