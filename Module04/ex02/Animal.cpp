#include "Animal.hpp"

Animal::Animal(/* args */)
{
    std::cout << "The best " << this->_type << "(NO TYPE) ANIMAL of the world has been born!!!" << std::endl;
}

Animal::Animal(const Animal& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "The best " << this->_type << "(NO TYPE) ANIMAL COPY of the world has been born!!!" << std::endl;    
}

Animal::~Animal()
{
    std::cout << "The best " << this->_type << "(NO TYPE) ANIMAL of the word has died!!!" << std::endl;
}

void        Animal::makeSound() const
{
        std::cout << "OING, OING, OING !!!" << std::endl;
}

std::string Animal::getType() const
{
    return(this->_type);
}

void        Animal::setType(std::string type)
{
    this->_type = type;
}

Animal&     Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}
