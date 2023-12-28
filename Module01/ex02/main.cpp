#include <iostream>

int main(void){
    std::string stringVar;
    std::string *stringPTR;

    stringVar = "HI THIS IS BRAIN";
    stringPTR = &stringVar;
    std::string &stringREF = stringVar;
    std::cout << "The memory address of the string variable: " << &stringVar << std::endl;
    std::cout << "The memory address held by stringPTR     : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF     : " << &stringREF << std::endl;
    std::cout << "The value of the string variable         : " << stringVar << std::endl;
    std::cout << "The value pointed to by stringPTR        : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF        : " << stringREF << std::endl;
    return (0);
}