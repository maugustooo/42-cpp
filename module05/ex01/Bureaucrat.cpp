#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std :: cout << "Bureaucrat default constructor called" << std :: endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std :: cout << "Bureaucrat constructor called" << std :: endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std :: cout << "Bureaucrat copy constructor called" << std :: endl;
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std :: cout << "Bureaucrat assignation operator called" << std :: endl;
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std :: cout << "Bureaucrat destructor called" << std :: endl;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return stream;
}
