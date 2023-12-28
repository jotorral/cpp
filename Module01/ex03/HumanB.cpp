#include "HumanB.hpp"

    HumanB::HumanB(std::string pName) : name(pName){}
    HumanB::~HumanB(void){}
    void    HumanB::attack(){
        std::cout << this->name << " attacks with their " << this->weapon.getType() <<std::endl;
    }
