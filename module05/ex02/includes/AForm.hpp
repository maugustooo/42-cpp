#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	std::string const _target;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
public:
	AForm();
	AForm(std::string const name, std::string const target, int const gradeToSign, int const gradeToExecute);
	AForm(const AForm &form);
	AForm &operator=(AForm const &rSym);
	virtual ~AForm();
	
	std::string getName() const;
	std::string getTarget() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	
	void beSigned(Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;

	virtual void action() const = 0;
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
  	{
    	public:
      		const char *what() const throw();
  	};
};

std::ostream &operator<<(std::ostream &stream, AForm const &form);
