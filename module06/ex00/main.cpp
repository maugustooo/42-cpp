#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
		ScalarConverter scalar(argv[1]);
	else
	{
		std::cout << "---0---" << std::endl;
		ScalarConverter scalar("0");
		std::cout << "---42---" << std::endl;
		ScalarConverter scalar2("42");
		std::cout << "---41.5f---" << std::endl;
		ScalarConverter scalar3("41.5f");
		std::cout << "---105.4---" << std::endl;
		ScalarConverter scalar4("105.4");
		std::cout << "---nan---" << std::endl;
		ScalarConverter scalar5("nan");
		std::cout << "---inf---" << std::endl;
		ScalarConverter scalar6("+inf");
		std::cout << std::endl;
	}
}