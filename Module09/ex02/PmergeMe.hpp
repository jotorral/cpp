#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <algorithm> // For sort function
#include <ctime>
#include <cstring>
#include <list>

class PmergeMe
{
	private:
		std::deque<int>		_d;
		std::vector<int>	_v;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe (const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		void				setAddToContainer(int);

		void				sortObjectDeque();
		void				sortsDeque(std::deque<int>&);
		void				printDeque();

		void				sortObjectVector();
		void				sortsVector(std::vector<int>&);
		void				printVector();
};
