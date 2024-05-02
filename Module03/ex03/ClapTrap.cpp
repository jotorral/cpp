#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "********* Constructor ClapTrap por defecto" << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " has been born, and is ready to fight" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl; 
		this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has received a " << amount << " points attack!" << std::endl;
	this->_hitPoints = this->_hitPoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1)
	{
		std::cout << "ClapTrap " << this->_name << " has received " << amount << " points of energy!" << std::endl;
		this->_hitPoints = this->_hitPoints + amount;
		this->_energyPoints--;
	}
}

void	ClapTrap::attacks(ClapTrap &targetClapTrap)
{
	if (this->_energyPoints >= 1 && targetClapTrap._hitPoints >= 1)
	{
		attack(targetClapTrap._name);
		targetClapTrap.takeDamage(this->_attackDamage);
	}
}
