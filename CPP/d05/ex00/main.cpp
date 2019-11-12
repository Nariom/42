#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int	main ( void ) {

	std::cout << std::endl << " *** Bureaucrat(\"bernard\", 1) ***" << std::endl;
	Bureaucrat	bernard("bernard", 1);
	std::cout << bernard << std::endl << std::endl;
	
	std::cout << std::endl << " *** Bureaucrat(\"alain\", 150) ***" << std::endl;
	Bureaucrat	alain("alain", 150);
	std::cout << alain << std::endl << std::endl;

	std::cout << std::endl << " *** Bureaucrat(\"michel\", 0) ***" << std::endl;
	try {
		Bureaucrat	michel("michel", 0);
		std::cout << michel << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << " *** Bureaucrat(\"stephane\", 151) ***" << std::endl;
	try {
		Bureaucrat	stephane("stephane", 151);
		std::cout << stephane << std::endl << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << " *** ++alain ***" << std::endl;
	++alain;
	std::cout << alain << std::endl << std::endl;

	std::cout << std::endl << " *** --alain ***" << std::endl;
	--alain;
	std::cout << alain << std::endl << std::endl;

	std::cout << std::endl << " *** ++bernard ***" << std::endl;
	try {
		++bernard;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << " *** --alain ***" << std::endl;
	try {
		--alain;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl << std::endl;
	}

}