#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class   Cat: public Animal
{
	private:
		std::string _type;
		Brain		*_oneBrain;

	public:

		Cat();
		~Cat();
		Cat(const Cat& other);
		void		makeSound() const;
		std::string	getType() const;
		void		setType(std::string type);
		Cat&		operator=(const Cat& other);
};

#endif
