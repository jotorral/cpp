#include "Cat.hpp"

Cat::Cat()
{
	std::string ideas[100];
	this->_type = "Cat";
	std::cout << "The best " << this->_type << " of the world has been born!!!" << std::endl;
	ideas[0] = "I am a beautiful cat!";
	ideas[1] = "I use to say meow!";
	this->_oneBrain = new Brain(ideas);
}

Cat::Cat(const Cat& other)
{
	this->_type = other._type;
	this->_oneBrain = new Brain(*other._oneBrain);
	std::cout << "The best " << this->_type << "COPY of the world has been born!!!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "The best " << this->_type << " of the world is dying!!!" << std::endl;
	delete this->_oneBrain;
}

void    Cat::makeSound() const
{
	std::cout << "MEOW, MEOW, MEOW !!!" << std::endl;
}

std::string	Cat::getType() const
{
	return(this->_type);
}

void		Cat::setType(std::string type)
{
	this->_type = type;
}

Cat&		Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		this->_oneBrain = new Brain(*other._oneBrain);
	}
	return (*this);
}
