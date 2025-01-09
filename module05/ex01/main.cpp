#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 150);
		std::cout << *bureaucrat << std::endl;
		Form *form = new Form();
		std::cout << *form << std::endl;
		form->beSigned(*bureaucrat);
		std::cout << *form << std::endl;
		delete form;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 2" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Adelino", 1);
		Bureaucrat *b2 = new Bureaucrat("Fernando", 1);
		Form *form = new Form("Form", 1, 1);
		b1->signForm(*form);
		std::cout << *b1 << std::endl;
		std::cout << *b2 << std::endl;
		std::cout << *form << std::endl;
		b2->signForm(*form);
		std::cout << *form << std::endl;
		delete form;
		delete b1;
		delete b2;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 3" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Abilio", 150);
		Bureaucrat *b2 = new Bureaucrat("Emilio", 1);
		std::cout << *b1 << std::endl;
		std::cout << *b2 << std::endl;
		Form *form = new Form("Form", 1, 1);
		std::cout << *form << std::endl;
		try
		{
			form->beSigned(*b1);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			form->beSigned(*b2);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << *form << std::endl;
		delete form;
		delete b1;
		delete b2;
	}
}