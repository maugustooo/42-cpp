#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target 1");
    clap.takeDamage(3);
    clap.beRepaired(3);
    clap.attack("Target 2");
    clap.takeDamage(15);
    clap.attack("Target 3");

    std::cout << "\n=== ScavTrap Tests ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Target 4");
    scav.takeDamage(50);
    scav.beRepaired(30);
    scav.guardGate();
    scav.takeDamage(80);
    scav.attack("Target 5");

    std::cout << "\n=== FragTrap Tests ===" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Target 6");
    frag.takeDamage(70);
    frag.beRepaired(40);
    frag.highFivesGuys();
    frag.takeDamage(100);
    frag.attack("Target 7");

    std::cout << "\n=== End of Tests ===" << std::endl;
    return 0;
}
