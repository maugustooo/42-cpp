#include "Scalar.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const std::string &input) : _input(input)
{
	std::cout << "Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalar)
{
	*this = scalar;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rSym)
{
	if (this != &rSym)
		_input = rSym._input;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string input)
{
	int type = HandleInput(input);
	switch (type)
	{
	case CHAR:
		convertChar(input);
		break;
	case INT:
		convertInt(input);
		break;
	case FLOAT:
		convertFloat(input);
		break;
	case DOUBLE:
		convertDouble(input);
		break;
	default:
		break;
	}
}

std::string ScalarConverter::GetInput()
{
	return _input;
}

int ScalarConverter::GetType()
{
	return _type;
}

int ScalarConverter::HandleInput(const std::string input)
{
	if(input.length() == 1 && !isdigit(input[0]))
		return CHAR;
	if(isdigit(input[0]) || input[0] == '+' || input[0] == '-')
		return INT;
	if(input.find('.') != std::string::npos)
		return FLOAT;
	return DOUBLE;
}

