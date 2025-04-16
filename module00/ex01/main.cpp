#include "PhoneBook.hpp"

int main()
{
	PhoneBook PhoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Enter ADD, SEARCH OR EXIT: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			PhoneBook.add_contact();
		else if (command == "SEARCH")
			PhoneBook.search_contact();
		else
			std::cout << "Invalid command." << std::endl;
		std::string().swap(command);
	}
	return (0);
}
