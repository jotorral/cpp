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
	virtual ~Animal();
	virtual void			makeSound() const;
	virtual std::string		getType() const;
	virtual void			setType(std::string _type);
	virtual Animal&			operator=(const Animal& otro);
};

#endif
