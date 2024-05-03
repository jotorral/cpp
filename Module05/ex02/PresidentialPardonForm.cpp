#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5), _target("DEFAULT_PresidentialPardonForm_TARGET")
{
	std::cout << RED << "A default PresidentialPardonForm has been born!!!" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{

	std::cout << "PresidentialPardonForm " << this->_target << " has been born!!!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	this->_target = other._target;
	std::cout << "Copy-PresidentialPardonForm " << this->_target << " has been born!!!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm " << BLUE << this->_target << RED << " has died!!!" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (&other != this)
	{
		AForm::operator=(other);
		this->_target = other._target;
		std::cout <<"Copy Operator " << this->_target << "Signed flag: " << AForm::getSigned() << std::endl;
	}
	return (*this);
}

void	PresidentialPardonForm::setSigned(){}

void	PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	std::cout << GREEN << bureaucrat.getName() << this->_target << " has been pardoned by Zaphod Beeblebrox !!!" << RESET << std::endl;
}

/**

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {
        // Llama al operador de asignación de la clase base
        AForm::operator=(other);
        // Copia el miembro específico de PresidentialPardonForm
        _target = other._target;
    }
    return *this;
}

*/
