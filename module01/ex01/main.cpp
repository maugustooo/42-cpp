# include "Zombie.hpp"

int main()
{
	std::string ZombieName;
	int nzombies = 0;
	while (!std::cin.eof())
	{
		std::cout << "Enter number of zombies(between 1 and 1000):";
		std::cin >> nzombies;
		if (std::cin.fail() || nzombies < 1 || nzombies > 1000)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a  number of zombies between 1 and 1000.\n";
		}
		else
			break;
	}
	if (std::cin.eof())
		return 0;
	std::cout << "enter zombie name: ";
	std::cin >> ZombieName;
	Zombie *horde = zombieHorde(nzombies, ZombieName);
	if(!horde)
	{
		std::cerr << "Failed to create horde" << std::endl;
		return 1;
	}
	for (int i = 0; i < nzombies; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
