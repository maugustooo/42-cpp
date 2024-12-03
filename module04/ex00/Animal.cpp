#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type){
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &animal){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(Animal const &src){
    std::cout << "Animal assignation operator called" << std::endl;
    _type = src._type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const{
    return _type;
}


void Animal::makeSound() const{
    std::cout << "Animal makes a sound" << std::endl;
}