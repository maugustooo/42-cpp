# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        //orthodox canonical form:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &scavTrap);
        ScavTrap &operator=(ScavTrap const &rSym);
        ~ScavTrap();
        //methods:
        void attack(const std::string &target);
        void guardGate();
};

#endif