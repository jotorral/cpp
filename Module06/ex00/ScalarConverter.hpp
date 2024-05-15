#pragma once

#include <iostream>

#define	ERROR		0
#define CHARACTER	1
#define INTEGER		2
#define FLOAT		3
#define DOUBLE		4

class ScalarConverter
{
	public:
		static int		_int;
		static char		_char;
		static float	_float;
		static double	_double;
		static int		detectType(char*);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &other);

};

