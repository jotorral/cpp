#include "FpNum.hpp"
//#include <bitset>

int main( void ) {

	Fixed 		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;

/*	uint32_t *p = reinterpret_cast<uint32_t*>(&a);
    std::bitset<32> bits(*p);
	std::cout << "Binary number: " << bits << std::endl;
*/

	std::cout << ++a << std::endl;

/*	uint32_t *q = reinterpret_cast<uint32_t*>(&a);
    std::bitset<32> bats(*q);
	std::cout << "Binary number: " << bats << std::endl;
*/	

	std::cout << a << std::endl;

/*	uint32_t *r = reinterpret_cast<uint32_t*>(&a);
    std::bitset<32> bots(*r);
	std::cout << "Binary number: " << bots << std::endl;
*/

	std::cout << a++ << std::endl;

/*	uint32_t *s = reinterpret_cast<uint32_t*>(&a);
    std::bitset<32> buts(*s);
	std::cout << "Binary number: " << buts << std::endl;
*/
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
/*
	std::cout << "\n\n" << Fixed::min( a, b ) << "\n\n" << std::endl;

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	if (a.getRawBits() > b.getRawBits())
		std::cout << a << " is bigger than " << b << std::endl;
	else
		std::cout << a << " is not bigger than " << b << std::endl;

	if (a.getRawBits() < b.getRawBits())
		std::cout << a << " is smaller than " << b << std::endl;
	else
		std::cout << a << " is not smaller than " << b << std::endl;

	if (a.getRawBits() >= b.getRawBits())
		std::cout << a << " is bigger than or equal to " << b << std::endl;
	else
		std::cout << a << " is not bigger than or equal to " << b << std::endl;

	if (a.getRawBits() <= b.getRawBits())
		std::cout << a << " is smaller than or equal to " << b << std::endl;
	else
		std::cout << a << " is not smaller than or equal to " << b << std::endl;	

	if (a.getRawBits() == b.getRawBits())
		std::cout << a << " is equal to " << b << std::endl;
	else
		std::cout << a << " is not equal to " << b << std::endl;		

	if (a.getRawBits() != b.getRawBits())
		std::cout << a << " is different to " << b << std::endl;
	else
		std::cout << a << " is not different to " << b << std::endl;
	
	a = a + b;
	std::cout << "a + b = a = " << a << std::endl;

	a = a - b;
	std::cout << "a - b = a = " << a << std::endl;

	a = a * b;
	std::cout << "a * b = a = " << a << std::endl;

	a = a / b;
	std::cout << "a / b = a = " << a << std::endl;
*/
	return 0;
}
