#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET		"\033[0m"
#define BLACK		"\033[30m"
#define MAGENTA		"\033[35m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define ORANGE		"\033[38;2;255;128;0m"
#define ROSE		"\033[38;2;255;151;203m"
#define LBLUE		"\033[38;2;53;149;240m"
#define LGREEN		"\033[38;2;17;245;120m"
#define GRAY		"\033[38;2;176;174;174m"
#define RESET		"\033[0m"

template <typename T>
class Array
{
	public:
		Array<T>(): _n(0)//constructor por defecto: _nº de elementos 0 y _array puntero a cero.
		{
			_array = new T[_n];
			std::cout << YELLOW << "A default Array has been created with " << this->_n << " elements. The address of the array is: " << this->_array << "." << RESET << std::endl;
		}

		Array<T>(Array const &other): _n(other._n), _array(NULL)
		{
			try
			{
				_array = new T[other._n];// new T[other._n] asigna memoria para un array de _n elementos
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << "Unable to allocate memory." << std::endl;
			}
			for (size_t i = 0; i < _n; ++i)
			{
				this->_array[i] = other._array[i];
			}
			std::cout << MAGENTA << "A deep copy Array has been created with " << this->_n << " elements. The address of the array is: " << this->_array << "." << RESET << std::endl;
		}

		~Array<T>()
		{
			std::cout << BLUE << "A default Array has been destructed with " << this->_n << " elements. The address of the array was: " << this->_array << "." << RESET << std::endl;
			delete[] _array;
		}

		Array<T>& operator=(Array<T> const &other)
		{
			if (this != &other)
			{
				std::cout << MAGENTA << "A deep copy of an Array has been made with " << this->_n << " elements. The address of the array was: " << this->_array << ", and now is: ";
				if (_array != NULL)
				{
					delete[] _array;
				}
				_n = other._n;
				try
				{
					_array = new T[_n];
				}
				catch(const std::bad_alloc& e)
				{
					std::cerr << "Unable to allocate memory." << std::endl;
					exit(EXIT_FAILURE);
				}
				for (size_t i = 0; i < _n; ++i)
				{
					this->_array[i] = other._array[i];
				}
				std::cout << this->_array << "." << RESET << std::endl;
			}
			return *this;
		}

		T& operator[](unsigned int i)
		{
			if (i >= _n)
				throw std::out_of_range("Index out of range");
			return this->_array[i];
		}

		const T& operator[](unsigned int i) const
    	{
        	if (i >= _n)
        	{
        	    throw std::out_of_range("Index out of range");
        	}
        	return _array[i];
    	}

		Array<T>(unsigned int n): _n(n), _array(NULL)
		{
			try
			{
				_array = new T[_n];
			}
			catch(const std::bad_alloc&)
			{
				std::cerr << "Unable to allocate memory." << std::endl;
				exit(EXIT_FAILURE);
			}
			for (size_t i = 0; i < _n; ++i)
			{
				this->_array[i] = T(); // asigna a cada elemento el valor predeterminado de T: si es una clase llama al constructor predeterminado y si es int double puntero etc pone 0.
			}
			std::cout << RED << "An Array has been created with " << this->_n << " elements. The address of the array is: " << this->_array << "." << RESET << std::endl;
		}

		unsigned int size() const
		{
			return (_n);
		}

	private:
		unsigned    int _n;
		T *         _array;
};
