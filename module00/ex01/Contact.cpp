#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::setContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}
std::string Contact::getfirst_name()
{
	return _first_name;
}
std::string Contact::getlast_name()
{
	return _last_name;
}
std::string Contact::getnickname()
{
	return _nickname;
}