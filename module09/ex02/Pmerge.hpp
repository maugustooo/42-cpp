#pragma once
#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

class Pmerge
{
	private:
		std::deque<int> _stack;
		bool 			_error;	
	public:
		Pmerge();
		Pmerge(const Pmerge &copy);
		~Pmerge();
		Pmerge &operator=(const Pmerge &copy);
		void calculate(std::string str);
		void printStack();
};