#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind (T &intContainer, int i)
{
	typename T::iterator itr; //It is necessary to put typename at the front to avoid ambiguity to the compiler, so it doesn't believe it is an static atribute
	itr = std::find(intContainer.begin(), intContainer.end(), i); // std::find is included in tyhhe head <algorithm> of the standard library
	if (itr == intContainer.end())
		throw std::exception();
	return (itr);
}
