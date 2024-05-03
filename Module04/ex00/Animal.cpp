#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "The best " << this->_type << "(NO TYPE) ANIMAL of the world has been born!!!" << std::endl;
}
Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "The best " << this->_type << "(NO TYPE) COPIED ANIMAL of the world has been born!!!" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
    {
		// Avoid auto-asignation
		_type = other._type;
	}
	return(*this); // Returns a pointer to the new object that is a copy of the object passed as argument.
}

Animal::~Animal()
{
    std::cout << "The best " << this->_type << "(NO TYPE) ANIMAL of the word has died!!!" << std::endl;
}

void    Animal::makeSound() const
{
        std::cout << "OING, OING, OING !!!" << std::endl;
}

std::string Animal::getType() const
{
    return(this->_type);
}

void    Animal::setType(std::string type)
{
    this->_type = type;
}
