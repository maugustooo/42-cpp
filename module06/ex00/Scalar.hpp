#pragma once
#include <string>
#include <iostream>

class ScalarConverter
{
private:
	std::string _input;
public:
	ScalarConverter();
	ScalarConverter(const std::string &input);
	ScalarConverter(const ScalarConverter &scalar);
	ScalarConverter &operator=(ScalarConverter const &rSym);
	~ScalarConverter();
};