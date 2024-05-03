#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define TREE "       *      \n      * *      \n     *   *     \n    *     *    \n   *       *   \n  *         *  \n *           * \n******   ******\n     *   *     \n     *****     \n"

class	Bureaucrat;

class	PresidentialPardonForm: public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	virtual void		setSigned();
	void				beExecuted(Bureaucrat const &bureaucrat) const;
};

// std::ostream    &operator<<(std::ostream &OutputFlux, PresidentialPardonForm *object);

#endif
