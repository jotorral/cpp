#include "FpNum.hpp"

int main( void ){

	Fixed	a; // Test default constructor that initializes the fixed-point number value to 0.
	Fixed	b( a ); // Test copy constructor. This constructor call the copy assignment operator overload.
	Fixed	c;

	c = b; // Test copy assignment operator overload.

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
