#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & other)
{
	(void)other;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & other)
{
	(void)other;
	return *this;
}

AForm *Intern ::ShrubberyCreationFormCreate(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern ::RobotomyRequestFormCreate(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern ::PresidentialPardonFormCreate(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	typedef AForm *(Intern::*FormCreator)(std::string);
	FormCreator forms[3] = {
		&Intern::ShrubberyCreationFormCreate,
		&Intern::RobotomyRequestFormCreate,
		&Intern::PresidentialPardonFormCreate
	};

	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*forms[i])(target);
		}
	}
	throw AForm::NoFormException();
}