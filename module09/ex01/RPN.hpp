#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> _stack;
		bool 			_error;	
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN &operator=(const RPN &copy);
		void calculate(std::string str);
		void printStack();
};