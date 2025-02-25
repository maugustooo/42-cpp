#include "easyfind.hpp"

int main(void)
{
	{
		std::vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);
		try
		{
			std::cout << *easyfind(container, 5) << std::endl;
			std::cout << *easyfind(container, 10) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
