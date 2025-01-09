#pragma once
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm 
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		void action() const;
};
