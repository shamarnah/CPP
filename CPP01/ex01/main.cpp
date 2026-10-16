#include "Zombie.hpp"

int main()
{
	Zombie *z = zombieHorde(9, "Zombie");
	for (int i = 0; i < 9; i++)
		z[i].announce();
	//for (int i = 0; i < 9; i++)
		//z[i].~Zombie();
	delete[] z;
}