#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

ShrubberyCreationForm tree("TREE");
Bureaucrat	pedro ("PEDRO", 60);
tree.execute(pedro);
std::cout << std::endl;

RobotomyRequestForm robo("ROBO");
Bureaucrat	juan ("JUAN", 75);
robo.execute(juan);
std::cout << std::endl;

PresidentialPardonForm presi("PRESI");
Bureaucrat	dential ("DENTIAL", 80);
presi.execute(dential);
std::cout << std::endl;

/*	srand(time(NULL));
	Bureaucrat juan;
	Bureaucrat pedro("PEDRO", 75);
	Bureaucrat pedro2(pedro);

	std::cout << std::endl;
	juan.DecrementGrade();
	juan.IncrementGrade();
	
	std::cout << std::endl;
    Bureaucrat pablo("PABLO", 0);
	std::cout << &pablo << std::endl;
	
	ShrubberyCreationForm mod1;
	std::cout << std::endl;

	ShrubberyCreationForm mod2("Formulario A", 74, 150);
	std::cout << std::endl;

	ShrubberyCreationForm mod3(0, 151);
	std::cout << std::endl;

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
*/
	return (0);
}
