#pragma once
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>
#include <sstream>
class MissingException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Value not found";
		}
};

template <typename T>

typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw MissingException();
	return it;
}