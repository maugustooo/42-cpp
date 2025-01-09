#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		std::cout << "-----test1-----" << std::endl;
		Bureaucrat b1("Bureaucrat1", 1);
		Bureaucrat b2("Bureaucrat2", 1);
		Bureaucrat b3("Bureaucrat3", 1);

		Intern someRandomIntern;
		AForm* intern;
		try
		{
			std::cout << "--shrubbery" << std::endl;
			intern = someRandomIntern.makeForm("shrubbery creation", "Home");
			b1.signForm(*intern);
			b1.executeForm(*intern);
			std::cout << *intern << std::endl;
			delete intern;
			std::cout << "--Robotomy" << std::endl;
			intern = someRandomIntern.makeForm("robotomy request", "Bender");
			b2.signForm(*intern);
			b2.executeForm(*intern);
			std::cout << *intern << std::endl;
			delete intern;
			std::cout << "--presidential" << std::endl;
			intern = someRandomIntern.makeForm("presidential pardon", "Bender");
			b3.signForm(*intern);
			b3.executeForm(*intern);
			std::cout << *intern << std::endl;
			delete intern;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		std::cout << "-----test2-----" << std::endl;
		Bureaucrat b("Bureaucrat", 1);
		Intern someRandomIntern;
		AForm* rrf;
		try
		{
			rrf = someRandomIntern.makeForm("bad name", "Bender");
			b.signForm(*rrf);
			b.executeForm(*rrf);
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}