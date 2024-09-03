#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: insufficient amount of arguments." << std::endl;
		return(1);
	}
	PmergeMe p;
	for (int i = 1; i < argc; i++)
	{
		for (unsigned int j = 0; j < strlen(argv[i]); j++)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				std::cerr << "Los argumentos tienen que ser números enteros positivos" << std::endl;
				return (-1);
			}
		}
		if (atoi(argv[i]) < 0)
		{
			std::cerr << "Los argumentos tienen que ser positivos" << std::endl;
			return (-1);
		}
		p.setAddToContainer(atoi(argv[i]));
	}

	// *********************************************************************************************************************

	std::cout << "\nVector antes:   ";
	p.printVector();

	clock_t inicio = clock();
	p.sortObjectVector();
	clock_t fin = clock();

	std::cout << "Vector después: ";
	p.printVector();

	std::cout << "El tiempo de ejecución con vector es: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos." << std::endl;

	// *********************************************************************************************************************

	std::cout << "\nDeque antes:   ";
	p.printDeque();

	inicio = clock();
	p.sortObjectDeque();
	fin = clock();

	std::cout << "Deque después: ";
	p.printDeque();

	std::cout << "El tiempo de ejecución con deque es: " << double(fin - inicio) / CLOCKS_PER_SEC << " segundos.\n" << std::endl;

	return(0);
}
