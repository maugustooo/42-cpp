#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        //orthodox canonical form:
        Cat();
        Cat(const Cat &cat);
        Cat &operator=(Cat const &rSym);
        ~Cat();
        //methods:
        void makeSound() const;
};

#endif