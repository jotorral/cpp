#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat juan;
	Bureaucrat pedro("PEDRO", 75);
	Bureaucrat pedro2(pedro);

	std::cout << std::endl;
	juan.DecrementGrade();
	juan.IncrementGrade();
	
	std::cout << std::endl;
    Bureaucrat pablo("PABLO", 0);
	std::cout << &pablo << std::endl;
	
	Form mod1;
	std::cout << std::endl;

	Form mod2("Formulario A", 74, 150);
	std::cout << std::endl;

	std::cout << "----------------------" << std::endl;
	Form mod3(75, 151);
	std::cout << std::endl;

	Form mod4(75, 0);
	std::cout << std::endl;

	Form mod5(0, 75);
	std::cout << std::endl;

	Form mod6(151, 75);
	std::cout << "----------------------" << std::endl;

	std::cout << &mod2 << std::endl;
	pedro.signForm(mod2);
	mod2.beSigned(pedro);
	std::cout << &mod2 << std::endl;
	pedro.signForm(mod2);
	std::cout << "----------------------" << std::endl;

	pedro.IncrementGrade();
	mod2.beSigned(pedro);
	std::cout << &mod2 << std::endl;
	std::cout << "----------------------\n" << std::endl;


	return (0);
}
