#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main ( void ) {
	
	std::cout << std::endl << " *** Bureaucrat(\"alain\", 5) ***" << std::endl;
	Bureaucrat	alain("alain", 5);
	std::cout << alain << std::endl << std::endl;

	std::cout << std::endl << " *** Bureaucrat(\"michel\", 2) ***" << std::endl;
	Bureaucrat	michel("michel", 2);
	std::cout << michel << std::endl << std::endl;

	std::cout << std::endl << " *** Form(\"can i has root\", 2, 2) ***" << std::endl;
	Form		canIHasRoot("can i has root", 2, 2);
	std::cout << canIHasRoot << std::endl << std::endl;

	std::cout << std::endl << " *** Form(\"too high signGrade\", 0, 2) ***" << std::endl;
	try {
		Form		tooHighSignGrade("too high signGrade", 0, 2);
		std::cout << tooHighSignGrade << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << " *** Form(\"too high execGrade\", 2, 0) ***" << std::endl;
	try {
		Form		tooHighExecGrade("too high execGrade", 0, 2);
		std::cout << tooHighExecGrade << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << " *** Form(\"too low signGrade\", 151, 2) ***" << std::endl;
	try {
		Form		tooLowSignGrade("too low signGrade", 151, 2);
		std::cout << tooLowSignGrade << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << " *** Form(\"too low execGrade\", 2, 151) ***" << std::endl;
	try {
		Form		tooLowExecGrade("too low execGrade", 2, 151);
		std::cout << tooLowExecGrade << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << " *** alain.signForm(canIHasRoot) ***" << std::endl;
	alain.signForm(canIHasRoot);
	std::cout << canIHasRoot << std::endl << std::endl;

	std::cout << std::endl << " *** michel.signForm(canIHasRoot) ***" << std::endl;
	michel.signForm(canIHasRoot);
	std::cout << canIHasRoot << std::endl << std::endl;

}