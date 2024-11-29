#include"Zombie.hpp"

Zombie *Zombie::NewZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return zombie;
}
