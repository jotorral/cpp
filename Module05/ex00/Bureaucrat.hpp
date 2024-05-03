#ifndef BUREAUCRAFT_HPP
# define BUREAUCRAFT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat(std::string name, int grade);
    Bureaucrat&  operator=(const Bureaucrat& other);
    void DecrementGrade();
    void IncrementGrade();
    std::string getName();
    int         getGrade();
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

std::ostream    &operator<<(std::ostream &OutputFlux, Bureaucrat *object);

#endif
