#include "FpNum.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point	a(-2.0f, 3.0f);
	Point	b(3.0f, -1.0f);
	Point	c(5.0f, 6.0f);
	Point	point(5.0f, 6.0f);

	bool isInto = bsp(a, b, c, point);

	if (isInto == true)
		std::cout << "O.K.: Point is into the triangle" << std::endl;
	else
		std::cout << "K.O.: Point is outside the triangle" << std::endl;
	return (0);
}
