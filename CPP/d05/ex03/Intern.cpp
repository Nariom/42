#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( Intern const & src ) { *this = src; }

Intern::~Intern( void ) {}

Form *		Intern::makeForm(
	std::string const formName,
	std::string const target
)
{
	std::string	forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	Form *		form = 0;

	if (forms[0].compare(formName) == 0)
		form = new ShrubberyCreationForm(target);
	else if (forms[1].compare(formName) == 0)
		form = new RobotomyRequestForm(target);
	else if (forms[2].compare(formName) == 0)
		form = new PresidentialPardonForm(target);
	if (form)
		std::cout << "Intern create " << *form << std::endl;
	else
		std::cout << formName << " : form not found." << std::endl;
	return form;
}

Intern &	Intern::operator=(Intern const & rhs) { (void) rhs; return *this; }