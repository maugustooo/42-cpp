#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"
class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:

	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(Bureaucrat const &rSym);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	
	void incrementGrade();
	void decrementGrade();

	void signForm(Form &form);
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat);