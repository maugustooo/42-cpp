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
		Bureaucrat *bureaucrat1 = new Bureaucrat("Adelino", 1);
		try
		{
			std::cout << *bureaucrat1 << std::endl;
			bureaucrat1->incrementGrade();
			std::cout << *bureaucrat1 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete bureaucrat1;
		std::cout << std::endl;
		Bureaucrat *bureaucrat2 = new Bureaucrat("Adelino", 150);
		try
		{
			std::cout << *bureaucrat2 << std::endl;
			bureaucrat2->decrementGrade();
			std::cout << *bureaucrat2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		delete bureaucrat2;
		std::cout << std::endl;
	}
}