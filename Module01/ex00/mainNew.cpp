#include <iostream>

class   Zombie{
private:
	std::string	name;
public:
	Zombie(std::string zombieName);
	~Zombie (void);
	void	announce(void);
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
};

Zombie::Zombie(std::string zombieName){
	this->name = zombieName;
	std::cout << this->name << " has been created." << std::endl;
}

Zombie::~Zombie (void){
	std::cout << this->name << " has been freed cause destructor has been executed." << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name ){
	return (new Zombie(name));
}

void randomChump( std::string name ){
	std::cout << name << " ha sido creado" << std::endl;
	return;
}

int	main(){
	std::string	zombieNameHeap;
	std::string	zombieNameStack;

	std::cout << "Type in the name of the zombie to be allocated in stack (Zombie Stack): " << std::flush;
	std::getline(std::cin, zombieNameStack, '\n');
	randomChump(zombieNameStack);
	
	std::cout << "Type in the name of the zombie to be allocated in heap (Zombie Heap): " << std::flush;
	std::getline(std::cin, zombieNameHeap, '\n');
	Zombie *zombieHeap = newZombie(zombieNameHeap);
	zombieHeap->announce();

	std::cout << "Freeing " << zombieNameHeap << " using delete function" << std::endl;
	delete zombieHeap;
	return 0;
}