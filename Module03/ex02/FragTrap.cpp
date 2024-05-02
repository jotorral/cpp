#include "FragTrap.hpp"

FragTrap::FragTrap(std::string a): ClapTrap(a)
{
	this->_name = a;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been born, and is ready to fight" << std::endl;
	std::cout << "FragTrap " << this->_name << " HitPoints:                                 " << this->_hitPoints << std::endl;
	std::cout << "FragTrap " << this->_name << " EnergyPoints:                              " << this->_energyPoints << std::endl;
	std::cout << "FragTrap " << this->_name << " will cause this AttackDamage when attacks: " << this->_attackDamage << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " new values:" << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " HitPoints:                                 " << ClapTrap::_hitPoints << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " EnergyPoints:                              " << ClapTrap::_energyPoints << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " will cause this AttackDamage when attacks: " << ClapTrap::_attackDamage << "\n" << std::endl;

	
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << this->_name << " has spent 1 energyPoint to attack " << target << ", causing him " << this->_attackDamage << " points of damage!" << std::endl; 
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
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ":\n\tDo you want a high five?\n\t***  C O M E   O N  !!!  ***\n\tHere you go!!!\n" << std::endl;
}

void	FragTrap::printValues()
{
	std::cout << "FragTrap " << this->_name << " HitPoints:                                 " << this->_hitPoints << std::endl;
	std::cout << "FragTrap " << this->_name << " EnergyPoints:                              " << this->_energyPoints << std::endl;
	std::cout << "FragTrap " << this->_name << " will cause this AttackDamage when attacks: " << this->_attackDamage << "\n" << std::endl;
}
