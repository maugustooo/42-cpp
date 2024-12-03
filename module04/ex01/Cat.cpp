#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal::Animal(src){
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(Cat const &src){
    std::cout << "Cat assignation operator called" << std::endl;
    _type = src._type;
    _brain = src._brain;
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const{
    std::cout << "Cat makes a sound meow meow" << std::endl;
}



Brain *Cat::getBrain() const{
    return _brain;
}