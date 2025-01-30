#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string &input) : _input(input)
{
	std::cout << "Constructor called" << std::endl;
	convert(GetInput());
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
	case INF:
		convertInf(input);
		break;
	case NAN:
		convertNan();
		break;
	case INVALID:
		std::cout << "Invalid input" << std::endl;
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
	if(input.length() == 1 && input[0] != '+' && input[0] != '-' && input[0] != '.')
		return CHAR;
	if((input[0] >= '0' && input[0] <= '9') || input[0] == '+' || input[0] == '-')
	{
		bool has_char = false;
		bool is_int = true;
		int dots = 0;
		int fs = 0;
		for (unsigned long i = 0; i < input.length(); i++)
			if (input[i] < '0' || input[i] > '9')
			{
				is_int = false;
				if (input[i] != '.')
					has_char = true;
				if (input[i] == '.')
					dots ++;
				else if ((i == input.length() - 1 && input[i] == 'f'))
					fs ++;
				else
					break;
			}
		if(is_int == true && dots == 0 && fs == 0)
			return INT;
	if(dots > 0)
	{
		if (dots > 1 || fs > 1 || (has_char == true && fs != 1))
			return INVALID;
		if (fs == 0)
			return DOUBLE;
		else
			return FLOAT;
	}
	}	
	if(input == "-inff" || input == "+inff"
	|| input == "-inf" || input == "+inf")
		return INF;
	else if(input == "nan")
		return NAN;
	return INVALID;
}

