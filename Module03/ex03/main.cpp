#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
/*	ClapTrap	peter("Peter");
	ClapTrap	john("John");

	peter.attacks(john);

	ScavTrap	andrew("Andrew");
	ScavTrap	martin("Martin");

	andrew.attacks(martin);
	martin.beRepaired(5);
	martin.guardGate();

	FragTrap	alfred("Alfred");
	FragTrap	robert("Robert");

	alfred.attacks(robert);
	robert.beRepaired(5);
	robert.guardGate();
	alfred.highFivesGuys();
*/
	DiamondTrap	joseph("Joseph");
	DiamondTrap	paul("Paul");

	joseph.attacks(paul);
	paul.beRepaired(5);
	paul.guardGate();
	joseph.highFivesGuys();
	joseph.whoAmI();
	paul.whoAmI();

	return (0);
}
