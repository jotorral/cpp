#include "Zombie.hpp"

int			ammount;
std::string	zombieName;
Zombie		*horde;

int main()
{
	std::cout << "Introduce la cantidad de Zombies: " <<std::flush;
	std::cin >> ammount;
	std::cout << "Introduce un nombre de los Zombies: " <<std::flush;
	std::cin >> zombieName;
	horde = zombieHorde (ammount, zombieName);
	for (int i = 0; i < ammount; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
//	system ("leaks moar_brainz");
	return (0);
}
