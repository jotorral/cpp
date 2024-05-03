#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class   Brain
{
protected:
	std::string _ideas[100];

public:
	Brain(std::string ideas[]);
	Brain(const Brain& other);
	Brain();
	~Brain();
	void			ideasSetter(std::string ideas[100]);
	std::string*	ideasGetter();
	Brain&			operator=(const Brain& other);
};

#endif
