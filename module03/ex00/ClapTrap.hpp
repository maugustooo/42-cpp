#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public:
    	//orthodox canonical form:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &clapTrap);
        ClapTrap &operator=(ClapTrap const &rSym);
        ~ClapTrap();
        //methods:
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};