#include "Zombie.hpp"

Zombie::Zombie(){

}
Zombie::~Zombie(){

}

void    Zombie::announce()
{
    std::cout << Zombie::_name << std::endl;
}

void        Zombie::set_name(std::string name)
{
    this->_name = name;
}

