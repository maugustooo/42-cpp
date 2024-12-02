#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(){
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(FragTrap const &src){
    std::cout << "FragTrap Assignation operator called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << _name << " requests high fives from everyone!" << std::endl;
}