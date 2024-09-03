#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cfloat>

#define	ERROR		0
#define CHARACTER	1
#define INTEGER		2
#define FLOAT		3
#define DOUBLE		4
#define STRING		5

class ScalarConverter
{
	public:
		static std::string	_int;
		static std::string	_char;
		static std::string	_float;
		static std::string	_double;

		static int		detectType(std::string);
		static void		convert(std::string);
		static void		charToScalar(std::string);
		static void		stringToScalar(std::string);
		static void		floatToScalar(std::string);
		static void		intToScalar(std::string);
		static void		doubleToScalar(std::string);
		static void		errorToScalar(std::string);
		static bool		isInteger(std::string);
		static bool		isFloat(std::string);
		static bool		isDouble(std::string);
		static float	getFloat();
		static double	getDouble();

	private:
		static int			_int1;
		static char			_char1;
		static float		_float1;
		static double		_double1;

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
};

