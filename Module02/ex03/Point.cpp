# include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(float const a, float const b): _x(a), _y(b) {}

Point::Point(const Point &objectToBeCopied): _x(objectToBeCopied._x), _y(objectToBeCopied._y) {}

Point::Point(const Fixed& a, const Fixed& b): _x(a), _y(b) {} // We create a new constructor for the copy assignment operator overload

Point Point::operator=(const Point &objectToBeCopied) // Copy assignment operator overrload
{
	if (this != &objectToBeCopied)
	{
		Point newPoint(objectToBeCopied._x, objectToBeCopied._y);
		return (newPoint);
	}
	return (*this);
}

Point::~Point() {}

float Point::getFloatNumX() const
{
	return(static_cast<float>(this->_x.getRawBits() * pow(2, -_x.getFractBits())));
}

float Point::getFloatNumY() const
{
	return(static_cast<float>(this->_y.getRawBits() * pow(2, -_x.getFractBits())));
}
