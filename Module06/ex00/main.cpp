#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Debes introducir 1 parámetro" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	std::cout << "\nChar:   " << ScalarConverter::_char  << "\nInt:    " << ScalarConverter::_int  << "\nFloat:  " <<  ScalarConverter::_float << "\nDouble: " << ScalarConverter::_double << std::endl;
	
	return (0);
}
