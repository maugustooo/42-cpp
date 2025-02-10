#include "ScalarConverter.hpp"

void convertChar(const std::string input)
{
	char c = input[0];
	int asInt = static_cast<int>(c);
	float asFloat = static_cast<float>(c);
	double asDouble = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << asInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << asFloat << "f" << std::endl;
	std::cout << "double: " << asDouble << std::endl;
}

void convertInt(const std::string input)
{
	int asInt = std::atoi(input.c_str());
	char asChar = static_cast<char>(asInt);
	float asFloat = static_cast<float>(asInt);
	double asDouble = static_cast<double>(asInt);

	if (asChar < 32 || asChar > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << asChar << "'" << std::endl;
	std::cout << "int: " << asInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << asFloat << "f" << std::endl;
	std::cout << "double: " << asDouble << std::endl;
}

void convertFloat(const std::string input)
{
	float asFloat = std::atof(input.c_str());
	char asChar = static_cast<char>(asFloat);
	int asInt = static_cast<int>(asFloat);
	double asDouble = static_cast<double>(asFloat);

	if (asChar < 32 || asChar > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << asChar << "'" << std::endl;
	std::cout << "int: " << asInt << std::endl;
	std::cout << "float: " << asFloat << "f" << std::endl;
	std::cout << "double: " << asDouble << std::endl;
}

void convertDouble(const std::string input)
{
	double asDouble = std::atof(input.c_str());
	char asChar = static_cast<char>(asDouble);
	int asInt = static_cast<int>(asDouble);
	float asFloat = static_cast<float>(asDouble);

	if (asChar < 32 || asChar > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << asChar << "'" << std::endl;
	std::cout << "int: " << asInt << std::endl;
	if (asFloat == asDouble)
		std::cout << "float: " << asFloat << ".0f" << std::endl;
	else
		std::cout << "float: " << asFloat << "f" << std::endl;
	std::cout << "double: " << asDouble << std::endl;
}

void convertNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void convertInf(const std::string input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}