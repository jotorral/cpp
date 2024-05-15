#include "AForm.hpp"

AForm::AForm(): _name("DEFAULT_AFORM"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_signed = false;
	std::cout << RED << "A default AForm has been born!!! " << "Name: " << this->_name << " Signed: " << this->_signed << " Grade to Sign: " << this->_gradeToSign << " Grade to Execute: " << this->_gradeToExecute << RESET << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm with name: " << this->_name << " is being born!!! Signed: " << this->_signed << " Grade to Sign: " << this->_gradeToSign << " Grade to Execute: " << this->_gradeToExecute << std::endl;
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		try
		{
			throw AForm::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
	{
		try
		{
			throw AForm::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}

AForm::AForm(int gradeToSign, int gradeToExecute): _name("DEFAULT_AFORM2"), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_signed = false;
	std::cout << CYAN << "An AForm with name DEFAULT_AFORM2 is being born!!!" << "Name: " << this->_name << " Signed: " << this->_signed << " Grade to Sign: " << this->_gradeToSign << " Grade to Execute: " << this->_gradeToExecute << RESET << std::endl;
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		try
		{
			throw AForm::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
	{
		try
		{
			throw AForm::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_signed = false;
	std::cout << RED << "The AForm with name: " << BLUE << this->_name << RED << " is being born!!! Signed: " << this->_signed << " Grade to Sign: " << this->_gradeToSign << " Grade to Execute: " << this->_gradeToExecute << std::endl;
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		try
		{
			throw AForm::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
	{
		try
		{
			throw AForm::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

AForm::~AForm()
{
	std::cout << RED << "AForm with name: " << BLUE << this->_name << RED << " has died!!! Signed: " << this->_signed << " Grade to Sign: " << this->_gradeToSign << " Grade to Execute: " << this->_gradeToExecute << std::endl;
}

void	AForm::setSigned(bool signedForm)
{
	this->_signed = signedForm;
	std::cout << RED << "AForm with name: " << BLUE << this->_name << RED << " has been signed!!! Signed: " << this->_signed << " Grade to Sign: " << this->_gradeToSign << " Grade to Execute: " << this->_gradeToExecute << std::endl;
}

AForm&  AForm::operator=(const AForm& other)
{
	if (&other != this)
	{
		this->_signed = other._signed;
		std::cout << RED << "AForm with name: " << BLUE << this->_name << RED << " has received the signed status from " << other._name << " Signed: " << other._signed << " Grade to Sign: " << this->_gradeToSign << " Grade to Execute: " << this->_gradeToExecute << std::endl;
	}
	return(*this);
}

std::string	AForm::getName() const
{
	return(this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return(this->_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return(this->_gradeToExecute);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("AForm not signed!");
}

std::ostream    &operator<<(std::ostream &OutputFlux, AForm *object)
{
	OutputFlux << "\033[35mAForm with name: " << object->getName() << ":\n\tsigned: " << object->getSigned() << ", gradeToSign: " << object->getGradeToSign() << ", gradeToExecute: " << object->getGradeToExecute() << RESET << std::endl;
	return (OutputFlux);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
		std::cout << CYAN << bureaucrat.getName() << " (" << bureaucrat.getGrade() << ")" << GREEN << " has signed " << CYAN << this->_name << " (" << this->_gradeToSign << ")" << RESET << std::endl;
	}
	else
	{	
		std::cout << CYAN << bureaucrat.getName() << " (" << bureaucrat.getGrade() << ")" << GREEN << " cannot sign " << CYAN << this->_name << " (" << this->_gradeToSign << ")" << RESET << std::endl;
		try
		{
			throw AForm::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void	setSigned()
{
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < this->_gradeToExecute)
	{
		try
		{
			throw (AForm::GradeTooLowException());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	if (this->_signed == 0)
	{
		try
		{
			throw (AForm::FormNotSignedException());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}		
	}
}
