#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal"){
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type){
    std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal){
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = animal;
}

AAnimal &AAnimal::operator=(AAnimal const &src){
    std::cout << "AAnimal assignation operator called" << std::endl;
    _type = src._type;
    return *this;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const{
    return _type;
}

