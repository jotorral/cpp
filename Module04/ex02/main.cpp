#include    "Animal.hpp"
#include    "Dog.hpp"
#include    "Cat.hpp"
#include	"WrongCat.hpp"
#include	"WrongAnimal.hpp"

int main()
{
	const Animal* animalArr[4];

	std::cout << "\nCat o Dog pueden ser instanciados. Animal puede utilizarse como clase base, pero si intentas instanciar directamente un Animal, dara error.\n\n";
//	Animal	dog;
	Cat		meow;

	std::cout << std::endl;

	animalArr[0] = new Dog();
	std::cout << animalArr[0]->getType() << " says: ";
	animalArr[0]->makeSound();
	std::cout << std::endl;

	animalArr[1] = new Cat();
	std::cout << animalArr[1]->getType() << " says: ";
	animalArr[1]->makeSound();
	std::cout << std::endl;

	animalArr[2] = new Dog();
	std::cout << animalArr[2]->getType() << " says: ";
	animalArr[2]->makeSound();
	std::cout << std::endl;

	animalArr[3] = new Cat();
	std::cout << animalArr[3]->getType() << " says: ";
	animalArr[3]->makeSound();
	std::cout << std::endl;

	for (int i = 3; i>=0; i--)
	{
		delete	animalArr[i];
	}
	system("leaks a.out");
	return (0);
}
