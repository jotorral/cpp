#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
*/
	FragTrap	alfred("Alfred");
	FragTrap	robert("Robert");
//	std::string	target = "Robert";

//	alfred.attack(target);

	alfred.attacks(robert);
	robert.printValues();
	alfred.printValues();
	robert.beRepaired(5);
	robert.printValues();
	robert.guardGate();
	alfred.highFivesGuys();

	return (0);
}
