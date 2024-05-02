#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap(std::string a): ClapTrap(a + "_clap_name")
{
	this->_name = a;
//	this->_hitPoints = 100;
	this->_energyPoints = 50;
//	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been born, and is ready to fight" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl; 
	this->_energyPoints--;
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl; 
}

void	ScavTrap::attacks(ScavTrap &targetScavTrap)
{
	if (this->_energyPoints >= 1 && targetScavTrap._hitPoints >= 1)
	{
		attack(targetScavTrap._name);
		targetScavTrap.takeDamage(this->_attackDamage);
	}
}
