#include "HumanA.hpp"

	HumanA::HumanA(Weapon pWeapon, std::string pName) : weapon(pWeapon), name(pName){
	}
	HumanA::~HumanA(void){}
	void    HumanA::attack(){
		std::cout << this->name << " attacks with their " << this->weapon.getType() <<std::endl;
	}
