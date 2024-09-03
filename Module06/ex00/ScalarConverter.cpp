#include "ScalarConverter.hpp"

std::string ScalarConverter::_int = "";
std::string ScalarConverter::_char = "";
std::string ScalarConverter::_float = "";
std::string ScalarConverter::_double = "";
int 	ScalarConverter::_int1 = 0;
char	ScalarConverter::_char1 = '\0';
float	ScalarConverter::_float1 = 0.0f;
double	ScalarConverter::_double1 = 0.0;

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

bool	ScalarConverter::isInteger(std::string str)
{
	if ((str[0] == '+' || str[0] == '-') && !str.empty())
        str.erase(0, 1);									// Eliminar el primer carácter
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string str)
{
	std::string::size_type dot = 0;

	if (!str.empty() && (str[0] == '+' || str[0] == '-'))
        str.erase(0, 1);									// Eliminar el primer carácter
	if (!str.empty() && str[str.size() - 1] != 'f')
	{
		return(false);
	}
	for (std::string::size_type i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == '.')
			dot++;
	}
	if (dot > 1)
		return (false);
	for (std::string::size_type i = 0; i < str.size() - 1; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isDouble(std::string str)
{
	std::string::size_type dot = 0;

	if (!str.empty() && (str[0] == '+' || str[0] == '-'))
        str.erase(0, 1);									// Eliminar el primer carácter
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			dot++;
	}
	if (dot > 1)
		return (false);
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (false);
	}
	return (true);
}

int	ScalarConverter::detectType(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]) && str[0] >= 0x20 && str[0] < 0x7f)
		return(CHARACTER);
	else if (str == "-inf" || str == "+inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "nanf")
		return(STRING);
	else if (isInteger(str) == true)
		return(INTEGER);
	else if (isFloat(str) == true)
		return(FLOAT);
	else if (isDouble(str) == true)
		return(DOUBLE);

	return(ERROR);
}

void	ScalarConverter::convert(std::string str)
{
	int type = ScalarConverter::detectType(str);
	switch(type)
	{
		case CHARACTER:
		{
			ScalarConverter::charToScalar(str);
			return;
		}
		case STRING:
		{
			ScalarConverter::stringToScalar(str);
			return;
		}
		case FLOAT:
		{
			ScalarConverter::floatToScalar(str);
			return;
		}
		case INTEGER:
		{
			ScalarConverter::intToScalar(str);
			return;
		}
		case DOUBLE:
		{
			ScalarConverter::doubleToScalar(str);
			return;
		}
		case ERROR:
		{
			ScalarConverter::errorToScalar(str);
			return;
		}
	}
}

float	ScalarConverter::getFloat()
{
	return (_float1);
}

double	ScalarConverter::getDouble()
{

	return (_double1);
}

std::string	intToString(int i)
{
	std::stringstream	ss;
	ss <<  i;
	return (ss.str());
}

std::string floatToString (float f)
{
	std::stringstream	ss;
	ss << std::fixed << std::setprecision(1) << f << "f";
	return (ss.str());
}

std::string doubleToString (float d)
{
	std::stringstream	ss;
	ss << std::fixed << std::setprecision(1) << d;
	return (ss.str());
}

std::string charToString (char c)
{
	std::stringstream	ss;
	ss << "'" << c << "'";
	return (ss.str());
}

void ScalarConverter::charToScalar(std::string str)
{
	_int1 = static_cast<int>(str[0]);
	_char1 = static_cast<char>(str[0]);
	_float1 = static_cast<float>(str[0]);
	_double1 = static_cast<double>(str[0]);
	_int = intToString(_int1);
	_char = charToString(_char1);
	_float = floatToString(_float1);
	_double = doubleToString(_double1);
}

void ScalarConverter::stringToScalar(std::string str)
{
	std::string atrib = "impossible";
	_int = atrib;
	_char = atrib;
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		_double = str;
		_float = str + "f";
	}
	else
	{
		_float = str;
		_double = str.erase(str.size() - 1);
	}
}

void ScalarConverter::floatToScalar(std::string str)
{
	std::istringstream iss(str);
	if (!(iss >> _float1))
	{
		_float1 = 0;
		_int1 = 0;
		_char1 = 0;
		_double1 = 0;
		_float = "impossible";
		_int = "impossible";
		_char = "impossible";
		_double = "impossible";
		return;
	}
	_float = floatToString(_float1);

	_double1 = static_cast<double>(_float1);
	_double = doubleToString(_double1);

	try
	{
		if (_float1 > 2147483647 || _float1 < -2147483648)
			throw std::runtime_error("");
		_int1 = static_cast<int>(_float1);
		_int = intToString (_int1);
	}
	catch (const std::runtime_error& e)
	{
		_int1 = 0;
		_int = "impossible";
		_char = "impossible";
		return;
	}

	try
	{
		if (_float1 > 0x7e || _float1 < 0x20)
			throw std::runtime_error("");
		_char1 = static_cast<char>(_float1);
		_char = charToString(_char1);
	}
	catch (const std::runtime_error& e)
	{
		_char1 = 0;
		_char = "not printable";
		if (_float1 >= 256 || _float1 < 0)
			_char = "impossible";
	}
}

void ScalarConverter::intToScalar(std::string str)
{
	std::istringstream iss(str);
	if (!(iss >> _int1))
	{
		_float1 = 0;
		_int1 = 0;
		_char1 = 0;
		_double1 = 0;
		_float = "impossible";
		_int = "impossible";
		_char = "impossible";
		_double = "impossible";
		return;
	}
	_int = intToString(_int1);

	_float1 = static_cast<float>(_int1);
	_float = floatToString(_float1);

	_double1 = static_cast<double>(_int1);
	_double = doubleToString(_double1);
	
	try
	{
		if (_int1 > 0x7e || _int1 < 0x20)
			throw std::runtime_error("");
		_char1 = static_cast<char>(_int1);
		_char = charToString(_char1);
	}
	catch (const std::runtime_error& e)
	{
		_char1 = 0;
		_char = "not printable";
		if (_int1 > 255 || _int1 < 0)
			_char = "impossible";
	}
}

void ScalarConverter::doubleToScalar(std::string str)
{
	std::istringstream iss(str);
	if (!(iss >> _double1))
	{
		_float1 = 0;
		_int1 = 0;
		_char1 = 0;
		_double1 = 0;
		_float = "impossible";
		_int = "impossible";
		_char = "impossible";
		_double = "impossible";
		return;
	}
	_double = doubleToString(_double1);
	std::cout << "String double: " << _double << std::endl;
	try
	{
		if (_double1 > 2147483647 || _double1 < -2147483648)
			throw std::runtime_error("");
		_int1 = static_cast<int>(_double1);
		_int = intToString (_int1);
	}
	catch (const std::runtime_error& e)
	{
		_int1 = 0;
		_int = "impossible";
		_char = "impossible";
	}

	try
	{
		if (_double1 > 0x7e || _double1 < 0x20)
			throw std::runtime_error("");
		_char1 = static_cast<char>(_double1);
		_char = charToString(_char1);
	}
	catch (const std::runtime_error& e)
	{
		_char1 = 0;
		_char = "not printable";
		if (_double1 >= 256 || _double1 < 0)
			_char = "impossible";
	}

	try
	{
		if (_double1 > FLT_MAX || _double1 < -FLT_MAX)
		{
			throw std::runtime_error("");
		}
		_float1 = static_cast<float>(_double1);
		_float = floatToString (_float1);
	}
	catch (const std::runtime_error& e)
	{
		_float1 = 0;
		_float = "impossible";
	}
}

void ScalarConverter::errorToScalar(std::string str)
{
	(void) str;
	_float1 = 0;
	_int1 = 0;
	_char1 = 0;
	_double1 = 0;
	_float = "error";
	_int = "error";
	_char = "error";
	_double = "error";
}
