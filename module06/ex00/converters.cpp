#pragma once
#include "Scalar.hpp"

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

