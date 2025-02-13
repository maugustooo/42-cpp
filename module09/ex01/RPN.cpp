#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}


RPN &RPN::operator=(const RPN &copy)
{
	if (this == &copy)
		return *this;
	_stack = copy._stack;
	return *this;
}

RPN::~RPN() {}

int operands(std::string token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::calculate(std::string str)
{
	std::istringstream iss(str);
	std::string token;
	int char_count = 0;
	while (iss >> token)
	{
		if	(std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1])) || (token[0] == '+' && std::isdigit(token[1])))
		{
			int num;
			std::stringstream ss(token);
			ss >> num;
			if (num > 10)
			{
				_error = true;
				std::cout << "Number too big" << std::endl;
				return;
			}
		}
		else if (!operands(token))
			char_count ++;
		if (operands(token))
		{
			if (_stack.size() < 2)
			{
				_error = true;
				std::cout << "Not enough operands" << std::endl;
				return;
			}
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			if (token == "+")
				_stack.push(b + a);
			else if (token == "-")
				_stack.push(b - a);
			else if (token == "*")
				_stack.push(b * a);
			else if (token == "/")
				_stack.push(b / a);
		}
		else
		{
			try
			{
				_stack.push(atoi(token.c_str()));
			}
			catch (std::exception &e)
			{
				std::cout << "Invalid input" << std::endl;
				return;
			}
		}
	}
	if (char_count > 0)
	{
		_error = true;
		std::cout << "invalid input" << std::endl;
	}
}

void RPN::printStack()
{
	std::stack<int> tmp = _stack;
	
	if (_error)
		return;
	if(tmp.size() == 1)
	{
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	else
	{
		std::cout << "Invalid expression" << std::endl;
		return;
	}
	std::cout << std::endl;
}

