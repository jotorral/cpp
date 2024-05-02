#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "********* Constructor ClapTrap por defecto" << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\n* * ClapTrap " << this->_name << " has been born, and is ready to fight" << std::endl;
	std::cout << "* * ClapTrap " << this->_name << " has got the next hitPoints:    *" << this->_hitPoints << std::endl;
	std::cout << "* * ClapTrap " << this->_name << " has got the next energyPoints: *" << this->_energyPoints << std::endl;
	std::cout << "* * ClapTrap " << this->_name << " attackDamage when attacks:     *" << this->_attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "* * ClapTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
		std::cout << "* * ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage, which substracts from his hitPoints!" << std::endl; 
		this->_energyPoints--;
}

void	ClapTrap::attacks(ClapTrap &targetClapTrap)
{
	if (this->_energyPoints >= 1 && targetClapTrap._hitPoints >= 1)
	{
		attack(targetClapTrap._name);
		targetClapTrap.takeDamage(this->_attackDamage);
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "* * ClapTrap " << this->_name << " has received a " << amount << " points attack!" << std::endl;
	this->_hitPoints = this->_hitPoints - amount;
	std::cout << "* * ClapTrap " << this->_name << " has got the next hitPoints:    *" << this->_hitPoints << std::endl;
	std::cout << "* * ClapTrap " << this->_name << " has got the next energyPoints: *" << this->_energyPoints << std::endl;
	std::cout << "* * ClapTrap " << this->_name << " attackDamage when attacks:     *" << this->_attackDamage << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1)
	{
		std::cout << "* * ClapTrap " << this->_name << " has expent 1 point of energy to recover " << amount << " hitPoints!" << std::endl;
		this->_hitPoints = this->_hitPoints + amount;
		this->_energyPoints--;
		std::cout << "* * ClapTrap " << this->_name << " has got the next hitPoints:    *" << ClapTrap::_hitPoints << std::endl;
		std::cout << "* * ClapTrap " << this->_name << " has got the next energyPoints: *" << ClapTrap::_energyPoints << std::endl;
		std::cout << "* * ClapTrap " << this->_name << " attackDamage when attacks:     *" << ClapTrap::_attackDamage << std::endl;
	}
}
