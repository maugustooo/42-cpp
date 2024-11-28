#include "class.hpp"

int main()
{
	PhoneBook phone_book;
	std::string command;

	while (1)
	{
		std::cout << "Enter ADD, SEARCH OR EXIT: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phone_book.add_contact();
		else if (command == "SEARCH")
			phone_book.search_contact();
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
