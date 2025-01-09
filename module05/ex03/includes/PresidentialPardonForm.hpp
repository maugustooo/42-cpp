#pragma once
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &PresidentialPardon_source);
		void action() const;
};