#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap){
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src){
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target){
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_energyPoints <= 0)
        std::cout << "ClapTrap " << _name << " has no energy points to attack!" << std::endl;
    else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " has no hit points!" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " has no energy points and hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_energyPoints > 0 || _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
        _hitPoints += amount;
        _energyPoints--;
    }
    else if (_energyPoints >= 0)
        std::cout << "ClapTrap " << _name << " has no energy points to repair!" << std::endl;
    else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << _name << " has no hit points to repair!" << std::endl;
    else
        std::cout << "ClapTrap " << _name << " has no energy points and hit points to repair!" << std::endl;
}