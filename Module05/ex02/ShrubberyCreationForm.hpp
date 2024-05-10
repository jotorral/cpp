#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define TREE "       *      \n      * *      \n     *   *     \n    *     *    \n   *       *   \n  *         *  \n *           * \n******   ******\n     *   *     \n     *****     \n"

class	Bureaucrat;

class	ShrubberyCreationForm: public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	virtual void		setSigned();
	void				execute(Bureaucrat const &bureaucrat) const;
};

#endif
