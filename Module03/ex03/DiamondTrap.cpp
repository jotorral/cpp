#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " has been born, and is ready to fight" << std::endl;
}

void	DiamondTrap::attack (const std::string &target)
{
	ScavTrap::attack(target);
}
/*
void	DiamondTrap::attacks(DiamondTrap &targetDiamondTrap)
{
	ScavTrap::attacks(targetDiamondTrap);
	std::cout << this->_name << "attacks" << targetDiamondTrap._name << std::endl;
}
*/
void	DiamondTrap::guardGate()
{
	ScavTrap::guardGate();
}

void    DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << this->_name << ". My ClapTrap name is: " << ClapTrap::_name << "." << std::endl;
}
