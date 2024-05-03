#include "Dog.hpp"

Dog::Dog()
{
	std::string ideas[100];
	this->_type = "Dog";
	std::cout << "The best " << this->_type << " of the world has been born!!!" << std::endl;
	ideas[0] = "I am a beautiful dog!";
	ideas[1] = "I use to say bark!";
	this->_oneBrain = new Brain(ideas);
}

Dog::Dog(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		_oneBrain = new Brain(*other._oneBrain);
	}
	std::cout << "The best " << this->_type << " COPY of the world has been born!!!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "The best " << this->_type << " of the world is dying!!!" << std::endl;
	delete this->_oneBrain;
}

void    	Dog::makeSound() const
{

	std::cout << "BARK, BARK, BARK !!!" << std::endl;
}

std::string	Dog::getType() const
{
	return(this->_type);
}

void		Dog::setType(std::string type)
{
	this->_type = type;
}

Dog			&Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		this->_oneBrain = new Brain(*other._oneBrain);
	}
	return(*this);
}
