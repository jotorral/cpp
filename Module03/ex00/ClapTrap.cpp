#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\nClapTrap " << this->_name << " has been born, and is ready to fight\nHe has got the next points:" << std::endl;
	std::cout << "Hit points:    " << this->_hitPoints << std::endl;
	std::cout << "Energy points: " << this->_energyPoints << std::endl;
	std::cout << "Attack damage: " << this->_attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\nClapTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
		std::cout << "\nClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl; 
		this->_energyPoints--;
		std::cout << this->_name << "'s Energy points: " << this->_energyPoints << std::endl;
}

void	ClapTrap::attacks(ClapTrap &targetClapTrap)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1 && targetClapTrap._hitPoints >= 1)
	{
		attack(targetClapTrap._name);
		targetClapTrap.takeDamage(this->_attackDamage);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints = this->_hitPoints - amount;
	std::cout << "ClapTrap " << this->_name << " has received " << amount << " points of damage and has " << this->_hitPoints <<  " Hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1 && this->_hitPoints >= 1)
	{
		std::cout << "\nClapTrap " << this->_name << " has wasted 1 Energy points for been repaired, receiving " << amount << " Hit points back!" << std::endl;
		this->_hitPoints = this->_hitPoints + amount;	
		this->_energyPoints--;
		std::cout << this->_name << "'s Energy points: " << this->_energyPoints << std::endl;
		std::cout << this->_name << "'s Hit points: " << this->_hitPoints << std::endl;

	}
}
