#include "HumanA.hpp"

    HumanA::HumanA(void){}
    HumanA::~HumanA(void){}
    void    HumanA::attack(){
        std::cout << this->name << " attacks with their " << this->weapon.getType() <<std::endl;
    }