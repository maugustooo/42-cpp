#pragma once
#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

class PmergeMe
{
	private:
		std::deque<int> _deque;
		std::vector<int> _vector;
		bool 			_error;	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &copy);
		void start(int argc, char **argv);
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
