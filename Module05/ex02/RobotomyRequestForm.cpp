#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("DEFAULT_RobotomyRequestForm_TARGET")
{
	std::cout << RED << "A default RobotomyRequestForm has been born!!! -> target: " << this->_target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{

	std::cout << "RobotomyRequestForm -> target: " << this->_target << " has been born!!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm (other)
{
	this->_target = other._target;
	std::cout << "Copy-RobotomyRequestForm -> target: " << this->_target << " has been born!!!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm -> target: " << BLUE << this->_target << RED << " has died!!!" << RESET << std::endl;
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

void	RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if (rand() % 2 == 0)
	{
		std::cout << GREEN << bureaucrat.getName() << " -> target: " << this->_target << " drill, drill, drill, drill... has been robotomized successfully !!!" << RESET << std::endl;
		return;
	}
	else
		std::cout << RED << bureaucrat.getName() << " -> target: " << this->_target << BLUE << " drill, drill, drill, drill, drill, drill... robotomizing failed !!!" << RESET << std::endl;
}
