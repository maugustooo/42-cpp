#include "AForm.hpp"

AForm::AForm(): _name("default"), _target("default"), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
	_signed = false;
}

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExecute): _name(name), _target(target), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form constructor called" << std::endl;
	_signed = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &form): _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
	_signed = form._signed;
}

AForm &AForm::operator=(AForm const &rSym) {
	_signed = rSym._signed;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return _name;
}

std::string AForm::getTarget() const {
	return _target;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &Bureaucrat) const
{
	if(!_signed)
		throw FormNotSignedException();
	if(Bureaucrat.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	this->action();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed";
}

const char* AForm::NoFormException::what() const throw() {
	return "No form found";
}

std::ostream &operator<<(std::ostream &stream, AForm const &form) {
	stream << "Form " << form.getName() << " is ";
	if (form.getSigned())
		stream << "signed";
	else
		stream << "not signed";
	stream << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return stream;
}