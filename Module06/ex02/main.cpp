#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>


Base * generate(void)
{
	std::srand(static_cast<unsigned>(std::time(0)));
	int randomNumber = std::rand() % 3;
	switch (randomNumber)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "The object is type A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "The object is type B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "The object is type C" << std::endl;
	}
}

void identify(Base& p)
{
		Base tmp;
	
  try {
    tmp = dynamic_cast<A &>(p);
		(void) tmp;
    std::cout << "The class is A" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    tmp = dynamic_cast<B &>(p);
		(void) tmp;
    std::cout << "The class is B" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    tmp = dynamic_cast<C &>(p);
		(void) tmp;
    std::cout << "The class is C" << std::endl;
  } catch (std::exception &e) {
  }
}

int main()
{
	Base * obj = generate();
	Base &obj1 = *obj;
	identify(obj);
	identify(obj1);
	delete (obj);
	return 0;
}
