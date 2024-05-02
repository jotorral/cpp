#include "FpNum.hpp"

/******** C O N S T R U C T O R S ********/

Fixed::Fixed() //Constructor of object "a", when no parameters are received
{
	this->_fixedNum = 0;
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedNum): _fixedNum (fixedNum << _fractBits)//Constructor of object b, when an integer parameter is received
{
	this->_fixedNum = static_cast<int>(roundf(fixedNum * pow(2, this->_fractBits))); //This is redundant but it is just for learning
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum)//: _fixedNum(floatNum * pow(2, this->_fractBits)) //Constructor of object c when a floating point parameter is received
{
//	std::cout << "Float constructor called" << std::endl;
	this->_fixedNum = static_cast<int>(roundf(floatNum * pow(2, this->_fractBits)));
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& objectToBeCopied)/* : _fixedNum(other._fixedNum)*/ //Constructor of object d which makes a copy of the object b received as parameter
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = objectToBeCopied;
}

/******** O P E R A T O R S   O V E R L O A D E D ********/

Fixed&	Fixed::operator=(const Fixed& objectToBeCopied) // Function of operator =
{
// 	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedNum = objectToBeCopied.getRawBits();
	return(*this); // Returns the pointer to the new object which is a copy of the object received as argument
}

Fixed	Fixed::operator+(const Fixed& objectToBeAdded) // Function of operator +
{
	Fixed	addition(this->toFloat() + objectToBeAdded.toFloat());
	return (addition); // Returns a new object with the addition
}

Fixed	Fixed::operator-(const Fixed& substractorObject) // Function of operator -
{
	Fixed	substraction(this->toFloat() - substractorObject.toFloat());
	return (substraction); // Returns a new object with the result of the substraction
}

Fixed	Fixed::operator*(const Fixed& multiplierObject) // Function of operator *
{
	Fixed	multiplication(this->toFloat() * multiplierObject.toFloat());
	return (multiplication); // Returns a new object with the multiplication result
}

Fixed	Fixed::operator/(const Fixed& dividerObject) // Function of operator "/"
{
	Fixed	division(this->toFloat() / dividerObject.toFloat());
	return (division); // Returns a new object with the division result
}

/******** C O M P A R I S O N   O P E R A T O R S   O V E R L O A D E D ********/

bool	Fixed::operator>(const Fixed& other) const // Function operator >
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

/******** I N C R E M E N T   O P E R A T O R S   O V E R L O A D E D ********/

Fixed&	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1); // Pre-increments the value of _fixedNum with the minimum ammount possible
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1); // Pre-decrements the value of _fixedNum with the minimum ammount possible
	return (*this);
}

Fixed	Fixed::operator++(int ammount)
{
	Fixed	resultObject;

	resultObject = *this; // Post-increments the value of _fixedNum with the minimum ammount possible

	if (!ammount)
		ammount = 1;
	this->setRawBits(this->getRawBits() + ammount);
	return (resultObject);
}

Fixed	Fixed::operator--(int ammount)
{
	Fixed	resultObject;

	resultObject = *this; // Post-decrements the value of _fixedNum with the minimum ammount possible

	if (!ammount)
		ammount = 1;
	this->setRawBits(this->getRawBits() - ammount);
	return (resultObject);
}

/********** PUBLIC OVERLOADED MEMBER FUNCTIONS MIN/MAX *********/

const Fixed &Fixed::min(Fixed const &fixedPoint1, Fixed const &fixedPoint2)
{
	if (fixedPoint1 < fixedPoint2)
		return (fixedPoint1);
	else
		return (fixedPoint2);
}

const Fixed& Fixed::max(Fixed const &fixedPoint1, Fixed const &fixedPoint2)
{
	if (fixedPoint1 > fixedPoint2)
		return (fixedPoint1);
	else
		return (fixedPoint2);
}

const Fixed& Fixed::min(Fixed &fixedPoint1, Fixed &fixedPoint2)
{
	if (fixedPoint1 < fixedPoint2)
		return (fixedPoint1);
	else
		return (fixedPoint2);
}

const Fixed& Fixed::max(Fixed &fixedPoint1, Fixed &fixedPoint2)
{
	if (fixedPoint1 > fixedPoint2)
		return (fixedPoint1);
	else
		return (fixedPoint2);
}

/********** FUNCTIONS WHICH RETURN THE VALUE OF THE OBJECT ATRIBUTE IN OTHER FORMATS *********/

int Fixed::toInt( void ) const
{
	return (this->_fixedNum * pow(2, -this->_fractBits));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedNum * pow(2, -this->_fractBits)));
}

/********  O V E R L O A D   O F   T H E   I N S E R T I O N   O P E R A T O R : <<  ********/

std::ostream	&operator<<(std::ostream &str, Fixed const &_fixedNum) // Operator << function
{
 	return(str << _fixedNum.toFloat()); // Stores in str an stream of the variable _fixedNum converted to floating point format, so it can be printed as output stream
}

/************* G E T T E R S   A N D   S E T T E R S **************/

int Fixed::getRawBits( void ) const
{
//return the raw value of the fixed-point value.
	return (this->_fixedNum);
}

int	Fixed::getFractBits(void) const
{
	return (this->_fractBits);
}

void Fixed::setRawBits( int const raw )
{
//setss the raw value of the fixed-point number.
	this->_fixedNum = raw;
}
