#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>
#include <iomanip>

class Weapon{
    private:
        std::string _type;
    public:
        Weapon();
        ~Weapon();
        Weapon(std::string type);
        const std::string &getType();
        void setType(std::string type);
};

#endif
