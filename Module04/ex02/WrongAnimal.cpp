#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "The best " << this->_type << "(NO TYPE) WRONGANIMAL of the world has been born!!!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    std::cout << "The best " << this->_type << "(NO TYPE) WRONGANIMAL COPY of the world has been born!!!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The best " << this->_type << "(NO TYPE) WRONGANIMAL of the word has died!!!" << std::endl;
}

void            WrongAnimal::makeSound() const
{
        std::cout << "OING, OING, OING !!!" << std::endl;
}

std::string     WrongAnimal::getType() const
{
    return(this->_type);
}

void            WrongAnimal::setType(std::string type)
{
    this->_type = type;
}
WrongAnimal&    WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->_type = other._type;
    return(*this);
}
