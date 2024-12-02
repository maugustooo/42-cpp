#include "ClapTrap.hpp"

int main()
{
    {
        ClapTrap clapTrap("Kratos");
        ClapTrap clapTrap2("shrek");

        std::cout << std::endl << "-------------TESTE1------------------" << std::endl;
        clapTrap.attack("shrek");
        clapTrap2.takeDamage(5);
        clapTrap2.beRepaired(5);
    }
    {
        ClapTrap clapTrap;
        ClapTrap clapTrap2("Palagoso");

        std::cout  << std::endl << "-------------TESTE2------------------" << std::endl;
        clapTrap2.attack("ClapTrap");
        clapTrap.takeDamage(5);
        clapTrap.beRepaired(5);
    }
    {
        ClapTrap clapTrap3("El Primo");

        std::cout << std::endl << "-------------TESTE3------------------" << std::endl;
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
        clapTrap3.takeDamage(5);
        clapTrap3.beRepaired(5);
        clapTrap3.attack("Sipder Man");
    }
    return 0;
}