#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string a): ClapTrap(a)
{
	this->_name = a;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\nScavTrap " << this->_name << " has been born, and is ready to fight" << std::endl;
	std::cout << "ScavTrap " << this->_name << " has got the next hitPoints:     " << this->_hitPoints << std::endl;
	std::cout << "ScavTrap " << this->_name << " has got the next energyPoints:  " << this->_energyPoints << std::endl;
	std::cout << "ScavTrap " << this->_name << " attackDamage when attacks:      " << this->_attackDamage << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " has got the next hitPoints:    *" << ClapTrap::_hitPoints << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " has got the next energyPoints: *" << ClapTrap::_energyPoints << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " attackDamage when attacks:     *" << ClapTrap::_attackDamage << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " says goodbye forever!!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "\nScavTrap " << this->_name << " expends 1 point attacking ScavTrap " << target << ", who gets " << this->_attackDamage << " points of damage, which substracts from his hitPoints!" << std::endl; 
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " has got the next hitPoints:     " << this->_hitPoints << std::endl;
	std::cout << "ScavTrap " << this->_name << " has got the next energyPoints:  " << this->_energyPoints << std::endl;
	std::cout << "ScavTrap " << this->_name << " attackDamage when attacks:      " << this->_attackDamage << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " has got the next hitPoints:    *" << ClapTrap::_hitPoints << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " has got the next energyPoints: *" << ClapTrap::_energyPoints << std::endl;
	std::cout << "* * ClapTrap " << ClapTrap::_name << " attackDamage when attacks:     *" << ClapTrap::_attackDamage << std::endl;
}

void	ScavTrap::attacks(ScavTrap &targetScavTrap)
{
	if (this->_energyPoints >= 1 && targetScavTrap._hitPoints >= 1)
	{
		attack(targetScavTrap._name);
		targetScavTrap.takeDamage(this->_attackDamage);
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}

void	ScavTrap::printValues()
{
	std::cout << "FragTrap " << this->_name << " HitPoints:                                 " << this->_hitPoints << std::endl;
	std::cout << "FragTrap " << this->_name << " EnergyPoints:                              " << this->_energyPoints << std::endl;
	std::cout << "FragTrap " << this->_name << " will cause this AttackDamage when attacks: " << this->_attackDamage << "\n" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << "\nScavTrap " << this->_name << " is now in Gate keeper mode.\n" << std::endl; 
}
