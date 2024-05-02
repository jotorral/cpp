#include "FpNum.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl; // Function of operator << converts fixed point to float so it can be printed by std::cout
	std::cout << "b is " << b << std::endl; // Function of operator << converts fixed point to float so it can be printed by std::cout
	std::cout << "c is " << c << std::endl; // Function of operator << converts fixed point to float so it can be printed by std::cout
	std::cout << "d is " << d << std::endl; // Function of operator << converts fixed point to float so it can be printed by std::cout

	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // Prints the number converted to integer
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // Prints the number converted to integer
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // Prints the number converted to integer
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // Prints the number converted to integer
	return 0;
}
