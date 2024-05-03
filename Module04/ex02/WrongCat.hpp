#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class   WrongCat: public WrongAnimal
{
	private:

	protected:
		std::string _type;

	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();
		void		makeSound() const;
		std::string	getType() const;
		void		setType(std::string other);
		WrongCat&	operator=(const WrongCat& other);
};

#endif
