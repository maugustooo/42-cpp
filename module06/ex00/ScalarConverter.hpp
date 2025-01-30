#pragma once
#include <string>
#include <iostream>
#include <iomanip> 
#include <cstdlib>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define INF 5
#define NAN 6
#define INVALID 7
class ScalarConverter
{
private:
	std::string _input;
	int 		_type;
	static int HandleInput(const std::string input);
	int GetType();
	std::string GetInput();
public:
	ScalarConverter(const std::string &input);
	ScalarConverter(const ScalarConverter &scalar);
	ScalarConverter &operator=(ScalarConverter const &rSym);
	~ScalarConverter();

	static void convert(const std::string input);
};

void convertChar(const std::string input);
void convertInt(const std::string input);
void convertFloat(const std::string input);
void convertDouble(const std::string input);
void convertInf(const std::string input);
void convertNan();