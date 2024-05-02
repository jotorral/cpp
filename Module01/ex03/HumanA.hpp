#ifndef HUMANA_HPP

# define HUMANA_HPP

# include "Weapon.hpp"

class   HumanA{
private:
	std::string _name;
	Weapon      &_weapon; // &: se comporta como un alias y obliga a inicializarlo en el objeto al declararlo. Después no se puede cambiar la referencia (valor del puntero _weapon), aunque si el contenido de donde apunta.

public:
	HumanA(std::string _name, Weapon &_weapon);
	~HumanA(void);
	void    attack();
};

#endif
