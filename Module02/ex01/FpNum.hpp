#ifndef FPNUM
# define FPNUM

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int                 _fixedNum;
	static const int    _fractBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& otro);
	Fixed& operator=(const Fixed& otro);

	Fixed(const int fixedNum);
	Fixed(const float floatNum);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& str, const Fixed& fixedNum);
#endif
