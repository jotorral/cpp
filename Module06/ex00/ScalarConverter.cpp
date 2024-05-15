#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called!!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
	std::cout << "Copy constructor called!!" <<std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called!!" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)  other;
	return (*this);
}

int	ScalarConverter::detectType(char* argv)
{
	std::string str = argv;
	if (str.length() == 1 && !isdigit(str[0]))
		return(CHARACTER);
	else if (/* condition */)
	{
		/* code */
	}
	

}