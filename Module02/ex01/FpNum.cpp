#include "FpNum.hpp"

Fixed::Fixed() //Constructor of object "a"
{
	this->_fixedNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedNum): _fixedNum (fixedNum << _fractBits)//Constructor of object "b" (integer)
{
	this->_fixedNum = static_cast<int>(roundf(fixedNum * pow(2, this->_fractBits)));
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum)//: _fixedNum(floatNum * pow(2, this->_fractBits)) //Constructor of object "c" (floating point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedNum = static_cast<int>(roundf(floatNum * pow(2, this->_fractBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otro)/* : _fixedNum(otro._fixedNum)*/ //Constructor of object "d" (copy constructor-> copy of object "b")
{
	std::cout << "Copy constructor called" << std::endl;
	*this = otro;
}

Fixed& Fixed::operator=(const Fixed& object) //Function of operator =
{
 	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNum = object.getRawBits();
	return(*this); // Returns a pointer to the new object that is a copy of the object received as argument.
}

int Fixed::toInt(void) const
{
	return (this->_fixedNum * pow(2, -this->_fractBits));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedNum * pow(2, -this->_fractBits)));
}

std::ostream	&operator<<(std::ostream &str, Fixed const &_fixedNum) //Function of operator <<
{
 	return(str << _fixedNum.toFloat()); // Returns a pointer to the stream which is in floating point format.
}

int Fixed::getRawBits(void) const
{
//return the raw value of the fixed-point value.
	return (this->_fixedNum);
}

void Fixed::setRawBits(int const raw)
{
//sets the raw value of the fixed-point number.
	this->_fixedNum = raw;
}
