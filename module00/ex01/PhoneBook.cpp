#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {
}

PhoneBook::~PhoneBook() {
}	
std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::add_contact()
{
	int position = PhoneBook::_index % 8;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	std::cout << "First name:" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "Last name:" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Phone number:" << std::endl;
	std::getline(std::cin, phone_number);
	std::cout << "Darkest secret:" << std::endl;
	std::getline(std::cin, darkest_secret);
	if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty())
	{
		std::cout << "Invalid contact: All fields must be filled." << std::endl;
		return;
	}
	PhoneBook::_index++;
	PhoneBook::_contacts[position].setContact(first_name, last_name, nickname, phone_number, darkest_secret);
}

void PhoneBook::search_contact()
{
	if (_index > 0)
		std::cout << "     Index|First name|  Lastname|  Nickname|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (i < _index)
        {
            std::cout << std::setw(10) << i << "|" 
                      << std::setw(10) << truncate(_contacts[i].getfirst_name()) << "|" 
                      << std::setw(10) << truncate(_contacts[i].getlast_name()) << "|" 
                      << std::setw(10) << truncate(_contacts[i].getnickname()) << "|" << std::endl;
        }
    }
	std::string index;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, index);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7')
    {
        int i = index[0] - '0';
        if (i < _index)
        {
            std::cout << "First name: " << _contacts[i].getfirst_name() << std::endl;
            std::cout << "Last name: " << _contacts[i].getlast_name() << std::endl;
            std::cout << "Nickname: " << _contacts[i].getnickname() << std::endl;
        }
        else
            std::cout << "Invalid index: No contact at this position." << std::endl;	
    }
}
