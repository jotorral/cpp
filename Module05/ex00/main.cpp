#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat juan;
    Bureaucrat pedro("PEDRO", 75);
    Bureaucrat pedro2(pedro);
    Bureaucrat pablo("PABLO", 0);
    std::cout << &pablo << std::endl;
    Bureaucrat domingo("DOMINGO", 151);
    std::cout << &domingo << std::endl;
    return (0);
}
