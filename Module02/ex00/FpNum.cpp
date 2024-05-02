#include "FpNum.hpp"

Fixed::Fixed()
{
	_fixedNum = 0;
	std::cout << "Default constructor called" << std::endl;
//	setRawBits(888); // Tests setRawBits setter.
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otro)/* : _fixedNum(otro._fixedNum)*/ {
	std::cout << "Copy constructor called" << std::endl;
	*this = otro;
}

Fixed& Fixed::operator=(const Fixed& otro)
{
	if (this != &otro)
	{
		// Avoid auto-asignation
		_fixedNum = otro._fixedNum;
		// It is not necessary to copy _frctBits, because its value is assigned in the class for default.
	}
	std::cout << "Copy assignment operator called" << std::endl;
	int rawBits = otro.getRawBits();
	(void) rawBits;
	return(*this); // Returns a pointer to the new object that is a copy of the object passed as argument.
}

int Fixed::getRawBits( void ) const{
//return the raw value of the fixed-point value.
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNum);
}

void Fixed::setRawBits( int const raw ){
//sets the raw value of the fixed-point number.
	this->_fixedNum = raw;
}
