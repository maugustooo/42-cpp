#include <iostream>
#include <string>
#include <iomanip>

class Zombie{
	private:
		std::string _name;
	public:
	    Zombie();
		~Zombie();
		Zombie(std::string name);
		void announce();
		void set_name(std::string name);
};

Zombie *zombieHorde(int N, std::string name);