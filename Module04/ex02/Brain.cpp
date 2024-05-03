#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "My brain is thinking." << std::endl;
}

Brain::Brain(std::string ideas[])
{
	std::copy(ideas, ideas + 100, _ideas);
	std::cout << "My brain is thinking: " << _ideas[0] << " & " << _ideas[1] << std::endl;
}
Brain::Brain(const Brain& other)
{
	int i = 0;
	while (i < 100)
	{
		_ideas[i] = other._ideas[i];
		i++;
	}
	std::cout << "My COPY brain is thinking: " << _ideas[0] << " & " << _ideas[1] << std::endl;
}

Brain::~Brain()
{
	std::cout << "I am deleting a Brain with the next ideas: " << _ideas[0] << " & " << _ideas[1] << std::endl;
}

void 			Brain::ideasSetter(std::string ideas[])
{
	std::copy(ideas, ideas + 100, _ideas);
}
std::string*	Brain::ideasGetter()
{
	return (this->_ideas);
}

Brain&			Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return(*this);
}
