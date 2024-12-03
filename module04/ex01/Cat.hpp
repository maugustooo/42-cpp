#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        //orthodox canonical form:
        Cat();
        Cat(const Cat &cat);
        Cat &operator=(Cat const &rSym);
        ~Cat();
        //methods:
        void makeSound() const;
        Brain *getBrain() const;
};

#endif