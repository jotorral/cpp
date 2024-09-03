#include <ostream>
#include <iostream>
#include <string>

#define RESET		"\033[0m"
#define BLACK		"\033[30m"
#define MAGENTA		"\033[35m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\003[34m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"
#define ORANGE		"\033[38;2;255;128;0m"
#define ROSE		"\033[38;2;255;151;203m"
#define LBLUE		"\033[38;2;53;149;240m"
#define LGREEN		"\033[38;2;17;245;120m"
#define GRAY		"\033[38;2;176;174;174m"
#define RESET		"\033[0m"

template <typename T> 
void    iter(T *arr, int length, void (*f)(T const &arr))
{
	for (int i = 0; i < length; i++)
		f(arr[i]);
}

template <typename T> 
void    iter(T *arr, int length, void (*f)(T &arr))
{
	for (int i = 0; i < length; i++)
		f(arr[i]);
}

template <typename T>
void	toScreen(T const & str)
{
	std::cout << str;
}
