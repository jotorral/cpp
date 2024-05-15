#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
private:
	std::string const   _name;
	bool				_signed;
	int const           _gradeToSign;
	int const           _gradeToExecute;
public:
	AForm();
	AForm(const AForm& other);
	AForm(int gradeToSign, int gradeToExecute);
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();
	AForm& 			operator=(const AForm& other);
	std::string		getName() const;
	bool 			getSigned() const;
	int 			getGradeToSign() const;
	int 			getGradeToExecute() const;
	void			setSigned(bool signedForm);
	void			beSigned(Bureaucrat &bureaucrat);
	virtual void	setSigned() = 0;
	virtual void	execute(Bureaucrat const & executor) const;
	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream    &operator<<(std::ostream &OutputFlux, AForm *object);

#endif
