#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        //orthodox canonical form:
        Dog();
        Dog(const Dog &dog);
        Dog &operator=(Dog const &rSym);
        ~Dog();
        //methods:
        void makeSound() const;
        Brain *getBrain() const;
};

#endif