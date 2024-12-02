# include "ScavTrap.hpp"
ScavTrap::ScavTrap() : ClapTrap(){
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(){
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src){
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    _name = src._name;
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target){
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_energyPoints <= 0)
        std::cout << "ScavTrap " << _name << " has no energy points to attack!" << std::endl;
    else if (_hitPoints <= 0)
        std::cout << "ScavTrap " << _name << " has no hit points!" << std::endl;
    else
        std::cout << "ScavTrap " << _name << " has no energy points and hit points!" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}