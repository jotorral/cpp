
#include "Span.hpp"

Span::Span() : _N(0), _v(0)
{
	std::cout << "Span object of 0 elements constructed by default" << std::endl;
}

Span::Span(unsigned int n):_N(n), _v(0){
	std::cout << "Span object of " << _N << " elements (maximum) constructed" << std::endl;
}

Span::~Span(){
	std::cout << "Span object of " << _N << " elements (maximum) destructed" << std::endl;
}

Span::Span(const Span &other) : _N(other._N), _v(other._v)
{
	std::cout << "Span object of " << _N << " elements (maximum) constructed copying another Span." << std::endl;
}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_v = other._v;
		std::cout << "Copied all the elements of another Span with " << _N << " maximun elements." << std::endl;
	}
	return(*this);
}

void	Span::addNumber(int n)
{
	std::cout << "Trying to add:" << n << std::endl; 
	if (_v.size() >= _N)
		throw std::exception();
	else
	{
		_v.push_back(n);
	}
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + _v.size() > _N) //Si la cantidad de elementos existentes en el vector + los nuevos elementos a introducir exceden de _N ... 
	{
		throw std::overflow_error("Span cannot accommodate all new numbers");
	}
	_v.insert(_v.end(), begin, end); //Inserta los nuevos elementos a partir de la posición del iterador _v.end()
}

unsigned int	Span::shortestSpan()
{
	unsigned int span = 0xffffffff;
	if(_N <= 1 || _v.size() <= 1)
		throw std::exception();
	else
	{
		std::stable_sort(_v.begin(), _v.end());
		for (unsigned int i = 0; i < _N - 1; i++)
		{
			unsigned int result = std::abs(_v[i] - _v[i + 1]);
			if (result < span)
				span = result;
		}
	}
	return (span);
}

unsigned int	Span::longestSpan()
{
	unsigned int result = 0;
	if(_N <= 1)
		throw std::exception();
	else
	{
		std::sort(_v.begin(), _v.end());
		result = std::abs(_v[_N - 1] - _v[0]);
	}
	return (result);
}
