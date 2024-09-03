#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(2);
	}
	catch (std::exception &e)
	{
		std::cout << "You have tryed to add more elements to the vector than the maximum. The last element hasn't been added." << std::endl;
	}
	try
	{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector has less than 2 elements." << std::endl;
	}
	std::cout << std::endl;

	Span sp2 = Span(2);
	try
	{
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector has less than 2 elements." << std::endl;
	}

	try
	{
		sp2.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cout << "You have tryed to add more elements to the vector than the maximum. The last element hasn't been added." << std::endl;
	}
	try
	{
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector has less than 2 elements." << std::endl;
	}
	
	try
	{
		sp2.addNumber(16);
	}
	catch(const std::exception& e)
	{
		std::cout << "You have tryed to add more elements to the vector than the maximum. The last element hasn't been added." << std::endl;
	}
	try
	{
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector has less than 2 elements." << std::endl;
	}
	std::cout << std::endl;

	Span sp3 = Span(15000);
	std::vector<int> vec;
	for (int i = 0; i < 15000; i++)
		vec.push_back(i);
	try
	{
		sp3.addNumber(vec.begin(), vec.end());
	}
	catch (std::exception &e)
	{
		std::cout << "You have tryed to add more elements to the vector than the maximum. The last element hasn't been added." << std::endl;
	}
	try
	{
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector has less than 2 elements." << std::endl;
	}
	std::cout << std::endl;
/*
	Span sp4;
	sp4 = sp;
	try
	{
		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp4.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector has less than 2 elements." << std::endl;
	}
	std::cout << std::endl;

	Span sp5(sp);
	try
	{
		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp4.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Vector has less than 2 elements." << std::endl;
	}
	std::cout << std::endl;
*/
	return 0;
}
