#include <iostream>

class Zombie
{
    
private:
    std::string _name;

public:
    Zombie( std::string name );
    ~Zombie();
    void    announce( void );
    Zombie* newZombie( std::string name );
    void    randomChump( std::string name );
};

// It creates a zombie, name it, and return it so you can use it outside of the function scope. Ubica el string name en el HEAP 
Zombie *newZombie( std::string name ) {
    return (new Zombie( name ));
}

/*
ChatGPT propone ésta:
Zombie* newZombie(std::string name) {
    // Crear un Zombie en el heap y devolver un puntero a él
    Zombie* zombie = new Zombie(name);
    return zombie;
}
Madebypixel02 propone ésta:
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}
*/

// It creates a zombie, name it, and the zombie announces itself. Ubica el string en el STACK
void    randomChump( std::string name ) {
    Zombie  zombi( name );
    zombi.announce();
}

/*ChatGPT propone ésta:
void randomChump(std::string name) {
    // La cadena se almacena en el stack
    std::cout << "randomChump: " << name << std::endl;
}
*/

Zombie::Zombie( std::string name) {
    this->_name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

int main( void ) {
    std::string name;

    std::cout << "Creating zombie on the stack." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie zombi1(name);
    
    std::cout << "Creating zombie on the heap." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;

    Zombie *zombi2 = newZombie(name); //El segundo zombie (zombie2) introducido, se ubica en el heap mediante la función *newZombie que devuelve un puntero para utilizarlo después
    zombi2->announce();
    delete zombi2; //Hay que hacer un delete de zombie2 para liberar memoria, pues está en el heap

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("randi");
    return 0;
}