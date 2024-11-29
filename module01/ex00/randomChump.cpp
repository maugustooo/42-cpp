#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie *zombie = Zombie::NewZombie(name);
	if (!zombie)
	{
		std::cerr << "Failed to create zombie" << std::endl;
		return ;
	}
	zombie->announce();
	delete zombie;
}
