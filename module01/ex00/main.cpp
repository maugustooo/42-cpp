# include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	std::string ZombieName;

	std::cout << "enter zombie name: ";
	std::cin >> ZombieName;
	zombie = Zombie::NewZombie(ZombieName);
	if (!zombie)
	{
		std::cerr << "Failed to create zombie" << std::endl;
		return 1;
	}
	zombie->announce();
	delete zombie;
	randomChump(ZombieName);
	return 0;
}