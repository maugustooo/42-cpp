#include "Span.hpp"

int main()
{
	{
		std::cout << "---Subject Test---" << std::endl;
		Span sp = Span(10000);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "---Range Test---" << std::endl;
		Span sp = Span(10);
		std::vector<int> numbers;
		std::srand(std::time(0));
		for (int i = 0; i < 10; i++)
        	numbers.push_back(std::rand() % 10);
		for (int i = 0; i < 10; i++)
			std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "---empty Span Test---" << std::endl;
		Span sp = Span(5);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "---Full Span Test---" << std::endl;
		Span sp = Span(5);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
			sp.addNumber(5);
			sp.addNumber(6);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "---One Span Test---" << std::endl;
		Span sp = Span(5);
		try
		{
			sp.addNumber(1);
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}