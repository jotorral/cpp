#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
private:
	std::string const   _name;
	bool                _signed;
	int const           _gradeToSign;
	int const           _gradeToExecute;
public:
	Form();
	Form(const Form& other);
	Form(int gradeToSign, int gradeToExecute);
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form& 			operator=(const Form& other);
	std::string		getName() const;
	bool 			getSigned() const;
	int 			getGradeToSign() const;
	int 			getGradeToExecute() const;
	void			setSigned(bool signedForm);
	void			beSigned(Bureaucrat &bureaucrat);
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream    &operator<<(std::ostream &OutputFlux, Form *object);

#endif
