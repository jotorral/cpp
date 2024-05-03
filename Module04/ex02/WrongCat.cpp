#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "The best " << this->_type << " of the world has been born!!!" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "The best " << this->_type << " COPY of the world has been born!!!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "The best " << this->_type << " of the world has died!!!" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "WRONG MEOW, WRONG MEOW, WRONG MEOW !!!" << std::endl;
}

std::string	WrongCat::getType() const
{
    return(this->_type);
}

void    WrongCat::setType(std::string type)
{
    this->_type = type;
}

WrongCat&   WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        this->_type = other._type;
    return(*this);
}
