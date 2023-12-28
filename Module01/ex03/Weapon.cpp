#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(){
return (this->type);
}

void	Weapon::setType(std::string newType){
    this->type = newType;
}
