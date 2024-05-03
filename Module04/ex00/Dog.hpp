#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog: public Animal
{
	private:
		std::string _type;
		
	protected:

	public:
		Dog();
		Dog(const Dog& other);
		~Dog();
		void		makeSound() const;
		std::string	getType() const;
		void		setType(std::string type);
		Dog& operator=(const Dog& other);
};

#endif
