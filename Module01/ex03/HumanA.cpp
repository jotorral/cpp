#include "HumanA.hpp"

	HumanA::HumanA(std::string pName, Weapon &pWeapon) : _name(pName), _weapon(pWeapon){
	}
	HumanA::~HumanA(void){
//		   std::cout << this->_name << " destruido" << std::endl;
	}

	void    HumanA::attack(){
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() <<std::endl;
	}
