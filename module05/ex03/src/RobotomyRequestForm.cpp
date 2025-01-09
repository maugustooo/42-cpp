#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", target, 72, 45) {
	std::cout << getName() << " was created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << getName() << " was destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute()) {
	std::cout << getName() << " was copied" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &Robotomy_source) {
	if (this != &Robotomy_source)
		*this = Robotomy_source;
	return *this;
}

void RobotomyRequestForm::action() const
{
	srand(time(0));
	int i = rand() % 2;
	if (i == 0)
		std::cout << "BEEP... BOOP... ZZZZT... WHIRRRR... KZZZZT... " << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "BEEP... BOOP... ZZZZT... WHIRRRR... KRRR...clunk...\nERROR 404: " << getTarget() << " has not been robotomized" << std::endl;
}