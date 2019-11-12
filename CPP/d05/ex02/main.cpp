#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main ( void ) {
	
	std::cout << std::endl << " *** Bureaucrat(\"alain\", 150) ***" << std::endl;
	Bureaucrat				alain("alain", 150);
	std::cout << alain << std::endl << std::endl;

	std::cout << std::endl << " *** Bureaucrat(\"michel\", 1) ***" << std::endl;
	Bureaucrat				michel("michel", 1);
	std::cout << michel << std::endl << std::endl;

	std::cout << std::endl << " *** ShrubberyCreationForm(\"trees\") ***" << std::endl;
	ShrubberyCreationForm	scf("trees");
	std::cout << scf << std::endl << std::endl;

	std::cout << std::endl << " *** RobotomyRequestForm(\"zaz\") ***" << std::endl;
	RobotomyRequestForm		rrf("zaz");
	std::cout << rrf << std::endl << std::endl;

	std::cout << std::endl << " *** PresidentialPardonForm(\"42\") ***" << std::endl;
	PresidentialPardonForm		ppf("42");
	std::cout << ppf << std::endl << std::endl;

	std::cout << std::endl << " *** michel.executeForm(scf) ***" << std::endl;
	michel.executeForm(scf);
	std::cout << std::endl;

	std::cout << std::endl << " *** michel sign all ***" << std::endl;
	michel.signForm(scf);
	std::cout << std::endl;
	michel.signForm(rrf);
	std::cout << std::endl;
	michel.signForm(ppf);
	std::cout << std::endl;

	std::cout << std::endl << " *** alain.executeForm(scf) ***" << std::endl;
	alain.executeForm(scf);
	std::cout << std::endl;

	std::cout << std::endl << " *** michel execute all ***" << std::endl;
	michel.executeForm(scf);
	std::cout << std::endl;
	michel.executeForm(rrf);
	std::cout << std::endl;
	michel.executeForm(ppf);
	std::cout << std::endl;

	std::cout << std::endl << " *** michel execute RobotomyRequestForm multiple times ***" << std::endl;
	michel.executeForm(rrf);
	std::cout << std::endl;
	michel.executeForm(rrf);
	std::cout << std::endl;
	michel.executeForm(rrf);
	std::cout << std::endl;
	michel.executeForm(rrf);
	std::cout << std::endl;

}