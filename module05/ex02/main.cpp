#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "-----test1-----" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		bureaucrat->signForm(*shrubbery);
		std::cout << *shrubbery << std::endl;
		bureaucrat->executeForm(*shrubbery);
		delete bureaucrat;
		delete shrubbery;
	}
	{
		std::cout << std::endl;
		std::cout << "-----test2-----" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 44);
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Bender");
		bureaucrat->signForm(*robotomy);
		std::cout << *robotomy << std::endl;
		bureaucrat->executeForm(*robotomy);
		delete bureaucrat;
		delete robotomy;
	}
	{
		std::cout << std::endl;
		std::cout << "-----test3-----" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
		PresidentialPardonForm *presidentialPardonForm = new PresidentialPardonForm("Bender");
		bureaucrat->signForm(*presidentialPardonForm);
		std::cout << *presidentialPardonForm << std::endl;
		bureaucrat->executeForm(*presidentialPardonForm);
		delete bureaucrat;
		delete presidentialPardonForm;
	}
	{
		std::cout << std::endl;
		std::cout << "-----Bad tests 1-----" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 138);
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		bureaucrat->signForm(*shrubbery);
		std::cout << *shrubbery << std::endl;
		bureaucrat->executeForm(*shrubbery);
		delete bureaucrat;
		delete shrubbery;
	}
	{
		std::cout << std::endl;
		std::cout << "-----Bad tests 2-----" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 73);
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Bender");
		bureaucrat->signForm(*robotomy);
		std::cout << *robotomy << std::endl;
		bureaucrat->executeForm(*robotomy);
		delete bureaucrat;
		delete robotomy;
	}
	{
		std::cout << std::endl;
		std::cout << "-----Bad tests 3-----" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 6);
		PresidentialPardonForm *presidentialPardonForm = new PresidentialPardonForm("Bender");
		bureaucrat->signForm(*presidentialPardonForm);
		std::cout << *presidentialPardonForm << std::endl;
		bureaucrat->executeForm(*presidentialPardonForm);
		delete bureaucrat;
		delete presidentialPardonForm;
	}
}