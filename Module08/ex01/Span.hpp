#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <numeric>

class Span
{

	private:
		unsigned int    	_N;
		std::vector<int>	_v;

	public:
		Span();
		~Span();
		Span(const Span &other);
		Span &operator=(const Span &other);

		Span(unsigned int n);		

		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
