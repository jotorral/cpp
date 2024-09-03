#include "PmergeMe.hpp"

struct ComparePairsV
{
    bool operator()(const std::vector<int>& a, const std::vector<int>& b)
	{
        return (a.front() < b.front());//Returns true if first integer of the couple of vector a is < than the one in the vector b
    }
};

PmergeMe::PmergeMe()
{
	std::cout << "Default constructor." << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "Default destructor." << std::endl;
}

PmergeMe::PmergeMe (const PmergeMe &other): _d(other._d), _v(other._v){}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_v = other._v;
		this->_d = other._d;
	}
	return (*this);
}

void	PmergeMe::setAddToContainer(int i)
{
	_v.push_back(i);
	_d.push_back(i);
}

void	PmergeMe::printVector()
{
	for (size_t l = 0; l < _v.size(); ++l)
	{
		std::cout << _v[l] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sortsVector(std::vector<int>& input)
{
	size_t	size = input.size();

	// Base case: when vector has a single element, recursivity finishes
	if (size <= 1)
		return;

	// If vector has an odd number of elements, we remove one and keep it in "spare"
	int spare = -1;
	if (size % 2 != 0)
	{
        spare = input.back(); // Last element stored in 'spare'
		input.pop_back();
    }

	// Find the middle point of the vector
	std::vector<int>::iterator middle = input.begin() + size / 2;

	// Create the 2 new half vectors
	std::vector<int> left(input.begin(), middle);
	std::vector<int> right(middle, input.end());
/*
	for (size_t i = 0; i < left.size(); ++i)
	{
		std::cout << left[i] << " ";
	}
	std::cout << " LEFT" << std::endl;

	for (size_t i = 0; i < right.size(); ++i)
	{
		std::cout << right[i] << " ";
	}
	std::cout << " RIGHT" << std::endl;
*/
	// Recursivity with the 2 half new vectors
	sortsVector(left);
	sortsVector(right);

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	size_t	rightSize = right.size();
	size_t	leftSize = left.size();

	// Merge the 2 half vectors and stores the result in the input vector
	while (i < leftSize || j < rightSize)
	{
		if (j >= rightSize)
		{
			input[k] = left[i];
			k++;
			i++;
		}
		else if (i >= leftSize)
		{
			input[k] = right[j];
			k++;
			j++;			
		}
		else if (left[i] > right[j])
		{
			input[k] = right[j];
			k++;
			j++;
		}
		else
		{
			input[k] = left[i];
			k++;
			i++;
		}
	}
	// If the input vector had odd number of elements, we insert the spare element in the proper possition 
	if (spare != -1)
	{
		middle = std::lower_bound(input.begin(), input.end(), spare);
		input.insert(middle, spare);
	}
	// Shows int screen the resultant vector
/*	for (size_t i = 0; i < input.size(); ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << " INPUT" << std::endl;*/
}

void	PmergeMe::sortObjectVector(void)
{
	sortsVector(this->_v);
}

void	PmergeMe::sortObjectDeque(void)
{
	sortsDeque(this->_d);
}

void	PmergeMe::sortsDeque(std::deque<int>& input)
{
	size_t	size = input.size();

	// Base case: when deque has a single element, recursivity finishes
	if (size <= 1)
		return;

	// If deque has an odd number of elements, we remove one and keep it in "spare"
	int spare = -1;
	if (size % 2 != 0)
	{
        spare = input.back(); // Last element stored in 'spare'
		input.pop_back();
    }

	// Find the middle point of the deque
	std::deque<int>::iterator middle = input.begin() + size / 2;

	// Create the 2 new half deques
	std::deque<int> left(input.begin(), middle);
	std::deque<int> right(middle, input.end());
/*
	for (size_t i = 0; i < left.size(); ++i)
	{
		std::cout << left[i] << " ";
	}
	std::cout << " LEFT" << std::endl;

	for (size_t i = 0; i < right.size(); ++i)
	{
		std::cout << right[i] << " ";
	}
	std::cout << " RIGHT" << std::endl;
*/
	// Recursivity with the 2 half new deques
	sortsDeque(left);
	sortsDeque(right);

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	size_t	rightSize = right.size();
	size_t	leftSize = left.size();

	// Merge the 2 half deques and stores the result in the input deque
	while (i < leftSize || j < rightSize)
	{
		if (j >= rightSize)
		{
			input[k] = left[i];
			k++;
			i++;
		}
		else if (i >= leftSize)
		{
			input[k] = right[j];
			k++;
			j++;			
		}
		else if (left[i] > right[j])
		{
			input[k] = right[j];
			k++;
			j++;
		}
		else
		{
			input[k] = left[i];
			k++;
			i++;
		}
	}
	// If the input deque had odd number of elements, we insert the spare element in the proper possition 
	if (spare != -1)
	{
		middle = std::lower_bound(input.begin(), input.end(), spare);
		input.insert(middle, spare);
	}
	// Shows int screen the resultant deque
/*	for (size_t i = 0; i < input.size(); ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << " INPUT" << std::endl;*/
}

void	PmergeMe::printDeque()
{
	for (size_t l = 0; l < _d.size(); ++l)
	{
		std::cout << _d[l] << " ";
	}
	std::cout << std::endl;
}
