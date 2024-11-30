#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPtr = &str;
	std::string& stringREF = str;

	std::cout << "memory address of the string: " << &str << std::endl;
	std::cout << "memory address of the string pointer: " << stringPtr << std::endl;
	std::cout << "memory address of the string reference: " << &stringREF << std::endl;

	std::cout << "string: " << str << std::endl;
	std::cout << "string pointer: " << *stringPtr << std::endl;
	std::cout << "string reference: " << stringREF << std::endl;
	return 0;
}
