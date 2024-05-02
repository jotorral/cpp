#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap //ScavTrap has access to all members public and private of class Claptrap
{
	protected:
		unsigned int	_hitPoints;
		unsigned int	_attackDamage;

	public:
		FragTrap();
		FragTrap(std::string a);
		~FragTrap();
		void	highFivesGuys(void);
		void	attack(const std::string& target);
		void	guardGate();
		void	attacks(FragTrap &targetFragTrap);
};

# endif
