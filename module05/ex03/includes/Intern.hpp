#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *ShrubberyCreationFormCreate(std::string target);
		AForm *RobotomyRequestFormCreate(std::string target);
		AForm *PresidentialPardonFormCreate(std::string target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &Intern_source);
		~Intern();

		AForm *makeForm(std::string formName, std::string target);
};