#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("DEFAULT_ShrubberyCreationForm_TARGET")
{
	std::cout << RED << "A default ShrubberyCreationForm has been born!!!" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

	std::cout << "ShrubberyCreationForm " << this->_target << " has been born!!!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	this->_target = other._target;
	std::cout << "Copy-ShrubberyCreationForm " << this->_target << " has been born!!!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm " << BLUE << this->_target << RED << " has died!!!" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (&other != this)
	{
		AForm::operator=(other);
		this->_target = other._target;
		std::cout <<"Copy Operator " << this->_target << "Signed flag: " << AForm::getSigned() << std::endl;
	}
	return (*this);
}

void	ShrubberyCreationForm::setSigned(){}

void	ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	std::ofstream	treeFile;
	treeFile.open((this->_target + "_shrubbery").c_str());
	if (treeFile.fail())
	{
		std::cout << "Unable to open the tree file !!!" << std::endl;
		return;
	}
	treeFile << TREE;
	treeFile.close();
	std::cout << bureaucrat.getName() << " has created a shrubbery" << std::endl;
}

/**

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        // Llama al operador de asignación de la clase base
        AForm::operator=(other);
        // Copia el miembro específico de ShrubberyCreationForm
        _target = other._target;
    }
    return *this;
}

*/
