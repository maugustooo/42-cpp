#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", target, 25, 5) {
	std::cout << getName() << " was created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << getName() << " was destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute()) {
	std::cout << getName() << " was copied" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &PresidentialPardon_source) {
	if (this != &PresidentialPardon_source)
		*this = PresidentialPardon_source;
	return *this;
}

void PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}