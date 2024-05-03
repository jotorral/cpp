#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
private:

protected:
	std::string _type;
	
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();
	virtual void			makeSound() const;
	virtual std::string		getType() const;
	virtual void			setType(std::string type);
	virtual WrongAnimal&	operator=(const WrongAnimal& other);
};

#endif
