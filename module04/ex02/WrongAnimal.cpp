#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type){
    std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src){
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    _type = src._type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return _type;
}

void WrongAnimal::setType(const std::string &type){
    _type = type;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal makes a sound" << std::endl;
}
