#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
/*	ClapTrap	peter("Peter");
	ClapTrap	john("John");

	peter.attacks(john);
*/
	ScavTrap	andrew("Andrew");
	ScavTrap	martin("Martin");

	andrew.attacks(martin);
	martin.printValues();
	martin.beRepaired(5);
	martin.printValues();
	martin.guardGate();

	return (0);
}
