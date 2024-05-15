#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5), _target("DEFAULT_PresidentialPardonForm_TARGET")
{
	std::cout << RED << "A default PresidentialPardonForm has been born!!! -> target: " << this->_target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{

	std::cout << "PresidentialPardonForm -> target: " << this->_target << " has been born!!! " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm (other)
{
	this->_target = other._target;
	std::cout << "Copy-PresidentialPardonForm -> target: " << this->_target << " has been born!!!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm -> target: " << BLUE << this->_target << RED << " has died!!!" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (&other != this)
	{
		AForm::operator=(other);
		this->_target = other._target;
		std::cout <<"Copy Operator -> target: " << this->_target << "Signed flag: " << AForm::getSigned() << std::endl;
	}
	return (*this);
}

void	PresidentialPardonForm::setSigned(){}

void	PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	std::cout << GREEN << "Bureaucrat: " << bureaucrat.getName() << RESET << " with " << BLUE << getName() <<" -> target: " << this->_target << RED << " has been pardoned by Zaphod Beeblebrox !!!" << RESET << std::endl;
}
