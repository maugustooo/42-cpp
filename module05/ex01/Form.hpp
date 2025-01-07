#include "Bureaucrat.hpp"

class Form
{
private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
public:
	Form();
	Form(std::string const name, int const gradeToSign, int const gradeToExecute);
	Form(const Form &form);
	Form &operator=(Form const &rSym);
	~Form();
	
	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	
	void beSigned(Bureaucrat &bureaucrat);
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, Form const &form);
