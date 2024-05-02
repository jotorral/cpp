#include "HumanB.hpp"

	HumanB::HumanB(std::string pName) : _name(pName){
		this->_weapon = 0;
	}

	HumanB::~HumanB(void){
//        std::cout << this->_name << " destruido" << std::endl;
	}

	void    HumanB::attack(){
		if (this->_weapon != 0)
			std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
		else
			std::cout << this->_name << "cannot attack with a weapon" << std::endl;
	}

	void    HumanB::setWeapon(Weapon &_weapon){
		this->_weapon = &_weapon;
	}
