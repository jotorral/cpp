#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
private:

protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal& other);
	virtual					~Animal();
	virtual void			makeSound() const;
	virtual std::string		getType() const;
	void					setType(std::string type);
	Animal&					operator=(const Animal& other);
};

#endif
