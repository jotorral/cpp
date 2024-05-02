#include "FragTrap.hpp"

FragTrap::FragTrap(){}

FragTrap::FragTrap(std::string a): ClapTrap()
{
	this->_name = a;
	this->_hitPoints = 100;
//	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been born, and is ready to fight" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl; 
	this->_energyPoints--;
}

void	FragTrap::guardGate(){
	std::cout << "FragTrap " << this->_name << " is now in Gate keeper mode." << std::endl; 
}

void	FragTrap::attacks(FragTrap &targetFragTrap)
{
	if (this->_energyPoints >= 1 && targetFragTrap._hitPoints >= 1)
	{
		attack(targetFragTrap._name);
		targetFragTrap.takeDamage(this->_attackDamage);
//		std::cout << this->_name << "attacks FragTrap " << targetFragTrap._name << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ":\n\tDo you want a high five?\n\t***  C O M E   O N  !!!  ***\n\tHere you go!!!" << std::endl;
}
