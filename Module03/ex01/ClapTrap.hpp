#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap
{
protected:
	std::string		_name;
	int				_hitPoints;
	int				_energyPoints;
	int				_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string a);
	~ClapTrap();
	void	attack(const std::string& target);
	void	attacks(ClapTrap &targetClapTrap);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
