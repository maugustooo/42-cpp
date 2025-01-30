#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
		ScalarConverter scalar(argv[1]);
	else
	{
		std::cout << "---bad:42.4ff---" << std::endl;
		ScalarConverter scalarBad("42.4ff");
		std::cout << "---c---" << std::endl;
		ScalarConverter scalar("c");
		std::cout << "---42---" << std::endl;
		ScalarConverter scalar2("42");
		std::cout << "---41.5f---" << std::endl;
		ScalarConverter scalar3("41.5");
		std::cout << "---105.4f---" << std::endl;
		ScalarConverter scalar4("105.4f");
		std::cout << "---nan---" << std::endl;
		ScalarConverter scalar5("nan");
		std::cout << "---inf---" << std::endl;
		ScalarConverter scalar6("inf");
		std::cout << std::endl;
	}
}