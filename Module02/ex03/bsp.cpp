#include "FpNum.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float area1 = fabs(point.getFloatNumX() * b.getFloatNumY() + b.getFloatNumX() * c.getFloatNumY() + c.getFloatNumX() * point.getFloatNumY() - (point.getFloatNumX() * c.getFloatNumY() + c.getFloatNumX() * b.getFloatNumY() + b.getFloatNumX() * point.getFloatNumY())) / 2;
	float area2 = fabs(a.getFloatNumX() * point.getFloatNumY() + point.getFloatNumX() * c.getFloatNumY() + c.getFloatNumX() * a.getFloatNumY() - (a.getFloatNumX() * c.getFloatNumY() + c.getFloatNumX() * point.getFloatNumY() + point.getFloatNumX() * a.getFloatNumY())) / 2;
	float area3 = fabs(a.getFloatNumX() * b.getFloatNumY() + b.getFloatNumX() * point.getFloatNumY() + point.getFloatNumX() * a.getFloatNumY() - (a.getFloatNumX() * point.getFloatNumY() + point.getFloatNumX() * b.getFloatNumY() + b.getFloatNumX() * a.getFloatNumY())) / 2;
	float area = fabs(a.getFloatNumX() * b.getFloatNumY() + b.getFloatNumX() * c.getFloatNumY() + c.getFloatNumX() * a.getFloatNumY() - (a.getFloatNumX() * c.getFloatNumY() + c.getFloatNumX() * b.getFloatNumY() + b.getFloatNumX() * a.getFloatNumY())) / 2;

	std::cout << "Area 1        = " << area1 << std::endl;
	std::cout << "Area 2        = " << area2 << std::endl;
	std::cout << "Area 3        = " << area3 << std::endl;
	std::cout << "Suma de areas = " << area3 + area2 + area1 << std::endl;
	std::cout << "Area Total    = " << area << std::endl;
	if (area != area1 + area2 + area3 || area1 == 0 || area2 ==0 || area3 == 0)
		return (false);
	else
		return (true);
}
