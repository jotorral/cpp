#include "Form.hpp"

Form::Form(): _name("DEFAULT_FORM"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_signed = false;
	std::cout << RED << "A default Form has been born!!!" << RESET << std::endl;
}
Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form " << this->_name << " has been born!!!" << std::endl;
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		try
		{
			throw Form::GradeTooLowException();
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
			throw Form::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}

Form::Form(int gradeToSign, int gradeToExecute): _name("DEFAULT_FORM"), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_signed = false;
	std::cout << CYAN << "A Form with name DEFAULT_FORM has been born!!!" << RESET << std::endl;
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		try
		{
			throw Form::GradeTooLowException();
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
			throw Form::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	
	}
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_signed = false;
	std::cout << RED << "The Form " << BLUE << this->_name << RED << " has been born!!!" << RESET << std::endl;
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		try
		{
			throw Form::GradeTooLowException();
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
			throw Form::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

Form::~Form()
{
	std::cout << RED << "Form " << BLUE << this->_name << RED << " has died!!!" << RESET << std::endl;
}

void	Form::setSigned(bool signedForm)
{
	this->_signed = signedForm;
}

Form&  Form::operator=(const Form& other)
{
	if (&other != this)
	{
		this->_signed = other._signed;
	}
	return(*this);
}

std::string	Form::getName() const
{
	return(this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return(this->_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return(this->_gradeToExecute);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream    &operator<<(std::ostream &OutputFlux, Form *object)
{
	OutputFlux << "\033[35mForm " << object->getName() << ":\n\tsigned: " << object->getSigned() << ", gradeToSign: " << object->getGradeToSign() << ", gradeToExecute: " << object->getGradeToExecute() << RESET << std::endl;
	return (OutputFlux);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
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
			throw Form::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
