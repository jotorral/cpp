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
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(const int fixedNum);
	Fixed(const float floatNum);

	int		getRawBits( void ) const;
	int		getFractBits(void) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	/* 6 comparison operators */
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	/* 4 arithmetic operators */
	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator*(const Fixed& other);
	Fixed	operator/(const Fixed& other);

	/* 4 increment/decrement operators */
	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int ammount);
	Fixed	operator--(int ammount);

	/* 4 overloaded member functions */
	static const Fixed& min(Fixed const &fixedPoint1, Fixed const &fixedPoint2);// son static porque se utiliza en la clase, pero no en una instancia
	static const Fixed& max(Fixed const &fixedPoint1, Fixed const &fixedPoint2);
	static const Fixed& min(Fixed &fixedPoint1, Fixed &fixedPoint2);
	static const Fixed& max(Fixed &fixedPoint1, Fixed &fixedPoint2);
};

std::ostream& operator<<(std::ostream& str, const Fixed& fixedNum);
#endif
