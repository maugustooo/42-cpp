#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    protected:
        std::string _type;
    public:
        //orthodox canonical form:
        AAnimal();
        AAnimal(const std::string &type);
        AAnimal(const AAnimal &animal);
        AAnimal &operator=(AAnimal const &rSym);
        virtual  ~AAnimal();
        //methods:
        virtual std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif