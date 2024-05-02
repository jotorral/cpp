#ifndef POINT
# define POINT

# include "FpNum.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(float const, float const);
		Point(const Fixed& a, const Fixed& b);
		Point(const Point &objectToBeCopied);
		~Point();
		Point operator=(const Point &objectToBeCopied);
		float getFloatNumX(void) const;
		float getFloatNumY(void) const;
};

#endif
