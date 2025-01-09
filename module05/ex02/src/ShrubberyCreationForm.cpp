#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137) {
	std::cout << getName() << " was created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << getName() << " was destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute()) {
	std::cout << getName() << " was copied" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Shrubbery_source) {
	if (this != &Shrubbery_source)
		*this = Shrubbery_source;
	return *this;
}

void ShrubberyCreationForm::action() const{
	std:: string const filename = getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::exception();
	file << "         |\n"
			"        -+-\n"
			"         A\n"
			"        /=\\\n"
			"      i/ O \\i\n"
			"      /=====\\\n"
			"      /  i  \\\n"
			"    i/ O * O \\i\n"
			"    /=========\\\n"
			"    /  *   *  \\\n"
			"  i/ O   i   O \\i\n"
			"  /=============\\\n"
			"  /  O   i   O  \\\n"
			"i/ *   O   O   * \\i\n"
			"/=================\\\n"
			"       |___|\n";
}