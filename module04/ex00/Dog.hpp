#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    //orthodox canonical form:
    Dog();
    Dog(const Dog &dog);
    Dog &operator=(Dog const &rSym);
    ~Dog();
    //methods:
    void makeSound() const;
};

#endif