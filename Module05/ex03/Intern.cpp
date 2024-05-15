#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "A new Intern has been born" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "A new InternCopy has been born" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "An Intern has died" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
	(void) other;
	return (*this);
}

AForm *makePresidentialForm(const std::string target)
{
	std::cout << RED << "Intern creates PresidentialPardonForm..." << RESET << std::endl;
	return(new PresidentialPardonForm(target));
}

AForm *makeRobotomyForm(const std::string target)
{
	std::cout << RED << "Intern creates RobotomyRequestForm..." << RESET << std::endl;
	return(new RobotomyRequestForm(target));
}

AForm *makeShrubberyForm(const std::string target)
{
	std::cout << RED << "Intern creates ShrubberyCreationForm..." << RESET << std::endl;
	return(new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string formType, const std::string targetForForm)
{
	std::string formName[] = {"PresidentialPardonForm","RobotomyRequestForm","ShrubberyCreationForm", "presidential pardon","robotomy request","shrubbery creation"};
	AForm *(*formFuncType[])(const std::string target) = {&makePresidentialForm, &makeRobotomyForm, &makeShrubberyForm, &makePresidentialForm, &makeRobotomyForm, &makeShrubberyForm};
	for (int i = 0; i < 6; i++)
	{
		if (formType == formName[i])
			return formFuncType[i](targetForForm);
	}
	return(0);
}
