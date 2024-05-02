#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap //ScavTrap has access to all members public and private of class Claptrap
{
	private:

	public:
		FragTrap(std::string a);
		~FragTrap();
		void	highFivesGuys(void);
		void	attack(const std::string& target);
		void	guardGate();
		void	attacks(FragTrap &targetFragTrap);
		void	printValues();
};

# endif
