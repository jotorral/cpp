#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat juan; //constructor por defecto
	Bureaucrat pedro("PEDRO", 75); //constructor con pase de atributos en parámetros
	Bureaucrat pedro2(pedro); //constructor de copia
	juan = pedro; //sobrecarga del operador =
	Bureaucrat pablo("PABLO", 0); //constructor con grado muy alto
	std::cout << &pablo << std::endl; //sobrecarga del operador << que muestra atributos
	Bureaucrat domingo("DOMINGO", 151); //constructor con grado muy bajo
	std::cout << &domingo << std::endl; //sobrecarga del operador << que muestra atributos
	return (0);
}
