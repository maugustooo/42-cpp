#pragma once
#include "AForm.hpp"

class RobotomyRequestForm: public AForm 
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		void action() const;
};