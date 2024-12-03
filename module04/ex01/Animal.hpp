#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        //orthodox canonical form:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &animal);
        Animal &operator=(Animal const &rSym);
        virtual  ~Animal();
        //methods:
        std::string getType() const;
        virtual void makeSound() const;
};

#endif