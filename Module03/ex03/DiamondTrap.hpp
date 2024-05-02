#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	
	public:
		DiamondTrap();
		DiamondTrap (std::string name);
		~DiamondTrap();
		void	attack(const std::string &target);
		void	attacks(DiamondTrap &targetDiamondTrap);
		void	guardGate();
		void	whoAmI();
};


# endif
