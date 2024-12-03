#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal::WrongAnimal(src){
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &src){
    std::cout << "WrongCat assignation operator called" << std::endl;
    _type = src._type;
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat makes a sound mmeeooww mmeeooww" << std::endl;
}