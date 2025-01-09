#include "Form.hpp"

Form::Form(): _name("default"), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
	_signed = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor called" << std::endl;
	_signed = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form): _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
	_signed = form._signed;
}

Form &Form::operator=(Form const &other) {
	_signed = other._signed;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else if (_signed)
		std::cout << "Form is already signed" << std::endl;
	else
	{
		_signed = true;
		std::cout << "Form is signed by " << bureaucrat.getName() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &stream, Form const &form) {
	stream << "Form " << form.getName() << " is ";
	if (form.getSigned())
		stream << "signed";
	else
		stream << "not signed";
	stream << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return stream;
}