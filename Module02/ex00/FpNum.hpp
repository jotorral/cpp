#ifndef FPNUM
# define FPNUM

# include <iostream>

class Fixed
{
private:
	int					_fixedNum;
	static const int	_fractBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& otro);
	Fixed& operator=(const Fixed& otro);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
