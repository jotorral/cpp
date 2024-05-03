#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("DEFAULT_BUREAUCRAT_NAME"), _grade(150)
{
	std::cout << YELLOW << "A default Bureaucrat has been born!!" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	std::cout << "\033[35mCopy Bureaucrat \033[0m" << this->_name << "\033[35m has been born!!" << RESET << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
		if (other._grade < 1)
		{
			this->_grade = 1;
			try
			{
				throw Bureaucrat::GradeTooHighException();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		else if (other._grade > 150)
		{
			this->_grade = 150;
			try
			{
				throw Bureaucrat::GradeTooLowException();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "\033[32mBureaucrat \033[0m" << this->_name << "\033[32m has been born!!!!!" << RESET << std::endl;
	if (this->_grade > 150)
	{
		this->_grade = 150;
		try
		{
			throw Bureaucrat::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else if (this->_grade < 1)
	{
		this->_grade = 1;
		try
		{
			throw Bureaucrat::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[33mA default Bureaucrat \033[0m" << this->_name << "\033[33m has died!!" << RESET << std::endl;
}

Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << YELLOW << "\033[34mBureaucrat assignation constructor called." << RESET << std::endl;
	if (&other != this)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

void Bureaucrat::DecrementGrade()
{
	if (_grade < 150)
	{
		_grade++;
		std::cout << GREEN << this->_name << " (" << this->_grade - 1 << ")" << YELLOW << " has decremented his grade to: " << GREEN << this->_grade << RESET << std::endl;
	}
	else
	{
		try
		{
			throw Bureaucrat::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << GREEN << this->_name << " (" << this->_grade << ")" << YELLOW << " will have now grade 150 (minimum grade). Its grade cannot be decremented to: " << GREEN << this->_grade + 1 << RESET << std::endl;
		this->_grade = 150;
	}
}

void Bureaucrat::IncrementGrade()
{
	if (_grade > 1)
	{
		_grade--;
		std::cout << GREEN << this->_name << " (" << this->_grade + 1 << ")" << YELLOW << " has incremented his grade to: " << GREEN << this->_grade << RESET << std::endl;
	}
	else
	{
		try
		{
			throw Bureaucrat::GradeTooHighException();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << GREEN << this->_name << " (" << this->_grade << ")" << YELLOW << " will have now grade 1 (maximum grade). Its grade cannot be incremented to: " << GREEN << this->_grade - 1 << RESET << std::endl;
		this->_grade = 1;

	}
}

std::ostream    &operator<<(std::ostream &OutputFlux, Bureaucrat *object)
{
	OutputFlux << "\033[35mBureaucrat " << object->getName() << ":\n\tgrade: " << object->getGrade() << RESET << std::endl;
	return (OutputFlux);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned() == true)
		std::cout << CYAN << this->_name << GREEN << " signed " << CYAN << form.getName() << RESET << std::endl;
	else
		std::cout << CYAN << this->_name << GREEN << " hasn't signed "  << CYAN << form.getName() << RESET << std::endl;
}
