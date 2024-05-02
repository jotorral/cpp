#ifndef HUMANB_HPP

# define HUMANB_HPP

# include "Weapon.hpp"

class   HumanB{
private:
	std::string _name;
	Weapon      *_weapon; // *: Indica que es un puntero que puede ser modificado, pudiendo alterar su valor en cualquier momento. Puede tomar incluso valor 0.

public:
	HumanB(std::string pName);
	~HumanB(void);
	void    attack();
	void    setWeapon(Weapon &_weapon);
};

#endif
