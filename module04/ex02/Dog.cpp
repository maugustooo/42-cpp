#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"){
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal::AAnimal(src){
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog &Dog::operator=(Dog const &src){
    std::cout << "Dog assignation operator called" << std::endl;
    _type = src._type;
    _brain = src._brain;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

void Dog::makeSound() const{
    std::cout << "Dog makes a sound woof woof" << std::endl;
}

Brain *Dog::getBrain() const{
    return _brain;
}