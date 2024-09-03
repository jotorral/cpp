#include "MutantStack.hpp"

int main()
{
	MutantStack<int>    mstack;
	std::cout << "5 added to stack" << std::endl;
	mstack.push(5);
	std::cout << "17 added to stack" << std::endl;
	mstack.push(17);

	std::cout << "Top of stack: ";
	std::cout << mstack.top() << std::endl; //Prints the top element of the stack in the screen

	std::cout << "Top of stack removed from stack." << std::endl;
	mstack.pop(); //Removes the top element of the stack

	std::cout << "Number of elements in stack: ";
	std::cout << mstack.size() << std::endl; //Shows the amount of elements of the stack

	std::cout << "3 added to stack" << std::endl;
	mstack.push(3);
	std::cout << "5 added to stack" << std::endl;
	mstack.push(5);
	std::cout << "737 added to stack" << std::endl;
	mstack.push(737);
	//[...]
	std::cout << "0 added to stack" << std::endl;
	mstack.push(0);

	std::cout << "Now stack has: " << std::endl;
	MutantStack<int>::iterator it = mstack.begin();//defines the iterator it and assigns to it the begining address
	MutantStack<int>::iterator ite = mstack.end();//defines the iterator ite and assigns to it the final address

	++it;//iterator class has ++ operator overwritten (overloaded)
	--it;//iterator class has -- operator overwritten (overloaded)
	while (it != ite)
	{
		std::cout << *it << std::endl;//iterator class has * operator overwriten (overloaded)
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
/*
int main()
{
//	MutantStack<int>    mstack;
	std::list<int>		mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

//	MutantStack<int>::iterator it = mstack.begin();
//	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
//	std::stack<int> s(mstack);
	std::list<int> s(mstack);
	return 0;
}
*/
