#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class   Cat: public Animal
{
	private:

	protected:
		std::string _type;

	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		void		makeSound() const;
		std::string	getType() const;
		void		setType(std::string type);
		Cat& operator=(const Cat& other);
};

#endif
