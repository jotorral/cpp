#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon(const std::string&);
    ~Weapon();
    const std::string   &getType();
    void                setType(std::string newType);
};

#endif
