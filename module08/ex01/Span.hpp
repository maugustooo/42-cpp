#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <cstdlib>
#include <ctime> 

class Span
{
	private:
		unsigned int		_vectorbr;
		std::vector<int>	_vector;
		Span();
	public:
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();
		void	addNumber(int number);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "The span is full";
				}
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "There is no span to calculate";
				}
		};
};