#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club); //Creates the object bob and inicializes name to "Bob" and Weapon to "crude spiked club" 
		bob.attack();
		club.setType("some other type of club"); // changes Weapon to "some other type of club"
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim"); //Creates the object jim and inicializes name to "Jim" and Weapon to "crude spiked club" 
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club"); // changes Weapon to "some other type of club"
		jim.attack();
	}
	return 0;
}