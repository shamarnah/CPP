#include "Zombie.hpp"

int main()
{
	Zombie *man = newZombie("man");
	man->announce();
	randomChump("woman");
	delete man;
	return 0;
}