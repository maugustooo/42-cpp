#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./pmergeMe [numbers]" << std::endl;
		return 1;
	}
	
	PmergeMe pmergeMe;
	try
	{
		pmergeMe.start(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}