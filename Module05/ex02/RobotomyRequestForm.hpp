#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <cstdlib>

class	Bureaucrat;

class	RobotomyRequestForm: public AForm
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	virtual void		setSigned();
	void				beExecuted(Bureaucrat const &bureaucrat) const;
};

// std::ostream    &operator<<(std::ostream &OutputFlux, RobotomyRequestForm *object);

#endif
