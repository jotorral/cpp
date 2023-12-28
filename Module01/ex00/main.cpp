#include "Zombie.hpp"

int	main(){
	std::string	zombieNameHeap;
	std::string	zombieNameStack;

	std::cout << "Type in the name of the zombie to be allocated in stack (Zombie Stack): " << std::flush;
	std::getline(std::cin, zombieNameStack, '\n');
	randomChump(zombieNameStack);
	
	std::cout << "Type in the name of the zombie to be allocated in heap (Zombie Heap): " << std::flush;
	std::getline(std::cin, zombieNameHeap, '\n');
	Zombie *zombieHeap = newZombie(zombieNameHeap);

	std::cout << zombieNameHeap << " Memory in Heap freed using delete function" << std::endl;
	delete zombieHeap;
//	(void) zombieHeap;
//	system("leaks Zombie");
	return 0;
}