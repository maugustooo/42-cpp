#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        //orthodox canonical form:
        WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal &operator=(WrongAnimal const &rSym);
        ~WrongAnimal();
        //methods:
        std::string getType() const;
        void makeSound() const;
};

#endif