#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{

	std::cout << "** Int Vector **" << std::endl;

	std::vector<int> intVector; //With vector

	for (int i = 0; i <= 40; i++)
		intVector.push_back(i+100); //It writes from 100 to 140
	try
	{
		std::cout << *easyfind(intVector, 125) << std::endl;
		std::cout << *easyfind(intVector, 180) << std::endl;
		std::cout << *easyfind(intVector, 135) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}

	std::cout << "** Int List **" << std::endl;

	std::list<int> intList; //With list

	for (int i = 0; i <= 40; i++) {
		intList.push_back(i+200); //It writes from 200 to 240
	}

	try
	{
		std::cout << *easyfind(intList, 225) << std::endl;
		std::cout << *easyfind(intList, 240) << std::endl;
		std::cout << *easyfind(intList, 250) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}

	return 0;
}
