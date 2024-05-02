#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap //ScavTrap has access to all members public and private of class Claptrap
{
	protected:
		unsigned int	_energyPoints;

	public:
		ScavTrap();
		ScavTrap(std::string a);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
		void	attacks(ScavTrap &targetScavTrap);
};




# endif
