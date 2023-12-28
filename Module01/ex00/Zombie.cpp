#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName){
	this->name = zombieName;
	announce();
}

Zombie::~Zombie (void){
	std::cout << this->name << " was contained in an object, and the object has been destructed." << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
