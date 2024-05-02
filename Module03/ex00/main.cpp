#include "ClapTrap.hpp"

int	main(void)
{
	//Verificado el funcionamiento cambiando en el constructor el parámetro _attackDamage(1) y verificando con el debugger
	ClapTrap	peter("Peter");
	ClapTrap	john("John");
	std::string	target = "John";

	peter.attacks(john);
	john.beRepaired(1);
	return (0);
}
