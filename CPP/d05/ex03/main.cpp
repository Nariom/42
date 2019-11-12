#include <iostream>
#include <exception>
#include "Intern.hpp"
#include "Form.hpp"

int	main ( void ) {

	Intern	someRandomIntern;
	Form *	form;

	form = someRandomIntern.makeForm("shrubbery creation", "Bender");
	if (form)
		std::cout << *form << std::endl;
	std::cout << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
		std::cout << *form << std::endl;
	std::cout << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (form)
		std::cout << *form << std::endl;
	std::cout << std::endl;
	form = someRandomIntern.makeForm("MAKE ME KING OF THE WORLD", "Bender");
	if (form)
		std::cout << *form << std::endl;
	std::cout << std::endl;

}