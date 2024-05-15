#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    private:

    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();

        Intern &operator=(const Intern &other);

        AForm *makeForm(const std::string form, const std::string target);
};

#endif
