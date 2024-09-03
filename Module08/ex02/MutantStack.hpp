#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <deque>
#include <list>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:

	public:
		MutantStack<T, Container>() //Constructor por defecto
		{
			std::cout << "Default constructor" << std::endl;
		}

		~MutantStack<T, Container>() //Destructor
		{
			std::cout << "Default destructor" << std::endl;
		}

		MutantStack<T, Container>(MutantStack<T, Container> const &other) //Constructor de copia
		{
			typename Container::const_iterator it = other.c.begin();
			typename Container::const_iterator end = other.c.end();

			this->c.clear(); //cleans the subyacent container

			for (; it != end; ++it) //copies the container. Deep copy.
			{
				this->c.push_back(*it);
			}
		}

		MutantStack<T, Container> &operator=(const MutantStack<T, Container> &other) //Sobrecarga el operador =
		{
			if (this != &other)
				this->c = other.c;
			return (*this);
		}

		typedef typename Container::iterator iterator; //Alias... iterator = Container::iterator
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};
