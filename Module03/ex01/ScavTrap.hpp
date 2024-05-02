#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap //ScavTrap has access to all members public and private of class Claptrap
{
	private:

	public:
		ScavTrap(std::string a);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
		void	attacks(ScavTrap &targetScavTrap);
		void	printValues();
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

# endif
