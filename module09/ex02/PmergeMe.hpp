#pragma once
#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iterator>

class PmergeMe
{
	private:
		std::deque<unsigned int> _deque;
		std::vector<unsigned int> _vector;
		bool 			_error;	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &copy);
		void start(unsigned int argc, char **argv);
		void handleSort();
		class InvalidArgsexception : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "invalid args";
				}
		};
};
