#include "Bureaucrat.hpp"

int main()
{
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("maugusto", 150);
		std::cout << *bureaucrat << std::endl;
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 2" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 1);
		std::cout << *bureaucrat << std::endl;
		bureaucrat->decrementGrade();
		std::cout << *bureaucrat << std::endl;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 3" << std::endl;
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("Adelino", 1);
			std::cout << *bureaucrat << std::endl;
			bureaucrat->incrementGrade();
			std::cout << *bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("Adelino", 150);
			std::cout << *bureaucrat << std::endl;
			bureaucrat->decrementGrade();
			std::cout << *bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}