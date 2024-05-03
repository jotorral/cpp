#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << "The best " << this->_type << " of the world has been born!!!" << std::endl;
}

Dog::Dog(const Dog& other)
{
    if (this != &other)
    {
        _type = other._type;
        std::cout << "The best " << this->_type << " COPY of the world has been born!!!" << std::endl;
    }
    else
        std::cout << "No Dog COPY has been born!!!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "The best " << this->_type << " of the world has died!!!" << std::endl;
}

Dog&        Dog::operator=(const Dog& other)
{
    if (this != &other)
        _type = other._type;
    return(*this);
}

void        Dog::makeSound() const
{

    std::cout << "BARK, BARK, BARK !!!" << std::endl;
}

std::string	Dog::getType() const
{
    return(this->_type);
}

void	    Dog::setType(std::string type)
{
    this->_type = type;
}
