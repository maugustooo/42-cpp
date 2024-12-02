#include "Fixed.hpp"

int main( void )
{
	Fixed a(5);
	Fixed b(5.01f);

	std::cout << "a = " << a <<std::endl;
	std::cout << "b = " << b <<std::endl;
	
	std::cout << "\n * * * * COMPARISON TESTS * * * * \n" << std::endl;
	bool c = a > b;
	std::cout << "a is greater than b: " << c << std::endl;
	c = a >= b;
	std::cout << "a is greater or equal to b: " << c << std::endl;
	c = a < b;
	std::cout << "a is smaller than b: " << c << std::endl;
	c = a <= b;
	std::cout << "a is smaller or equal to b: " << c << std::endl;
	c = a == b;
	std::cout << "a is equal to b: " << c << std::endl;
	c = a != b;
	std::cout << "a is different from b: " << c << std::endl;
	
	std::cout << "\n * * * * ARITHMETIC TESTS * * * * \n" << std::endl;
	std::cout << "a + b = " << a + b << std::endl; 
	std::cout << "a - b = " << a - b << std::endl; 
	std::cout << "a * b = " << a * b << std::endl; 
	std::cout << "a / b = " << a / b << std::endl; 

	std::cout << "\n * * * * INCREMENT TESTS * * * * \n" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "\n * * * * MIN/MAX TESTS * * * * \n" << std::endl;
	std::cout << "min(a,b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a,b) = " << Fixed::max(a, b) << std::endl;
return 0;
}
