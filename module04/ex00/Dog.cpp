#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal::Animal(src){
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog &Dog::operator=(Dog const &src){
    std::cout << "Dog assignation operator called" << std::endl;
    _type = src._type;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog makes a sound woof woof" << std::endl;
}