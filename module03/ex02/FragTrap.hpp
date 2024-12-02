#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        //orthodox canonical form:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &fragTrap);
        FragTrap &operator=(FragTrap const &rSym);
        ~FragTrap();
        //methods:
        void highFivesGuys();
};

#endif