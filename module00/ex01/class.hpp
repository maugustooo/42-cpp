#include <iostream>
#include <string>


class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		void add_contact();
		void search_contact();
};