#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "The best " << this->_type << " of the world has been born!!!" << std::endl;
}
Cat::~Cat()
{
	std::cout << "The best " << this->_type << " of the world has died!!!" << std::endl;
}

Cat::Cat(const Cat& other)
{
	if (this != &other)
		*this = other;
	std::cout << "The best COPIED" << this->_type << " of the world has been born!!!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		_type = other._type;
	return(*this);
}

void    Cat::makeSound() const
{
	std::cout << "MEOW, MEOW, MEOW !!!" << std::endl;
}

std::string	Cat::getType() const
{
	return(this->_type);
}

void    Cat::setType(std::string type)
{
	this->_type = type;
}
