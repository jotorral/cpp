#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("DEFAULT_RobotomyRequestForm_TARGET")
{
	std::cout << RED << "A default RobotomyRequestForm has been born!!!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{

	std::cout << "RobotomyRequestForm " << this->_target << " has been born!!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	this->_target = other._target;
	std::cout << "Copy-RobotomyRequestForm " << this->_target << " has been born!!!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm " << BLUE << this->_target << RED << " has died!!!" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (&other != this)
	{
		AForm::operator=(other);
		this->_target = other._target;
		std::cout <<"Copy Operator " << this->_target << "Signed flag: " << AForm::getSigned() << std::endl;
	}
	return (*this);
}

void	RobotomyRequestForm::setSigned(){}

void	RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	if (rand() % 2 == 0)
	{
		std::cout << GREEN << bureaucrat.getName() << " -> " << this->_target << " drill, drill, drill, drill... has been robotomized successfully !!!" << RESET << std::endl;
		return;
	}
	else
		std::cout << RED << bureaucrat.getName() << " -> " << this->_target << " drill, drill, drill, drill, drill, drill... robotomizing failed !!!" << RESET << std::endl;
}

/**

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        // Llama al operador de asignación de la clase base
        AForm::operator=(other);
        // Copia el miembro específico de RobotomyRequestForm
        _target = other._target;
    }
    return *this;
}

*/
