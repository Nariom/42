#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(
	ShrubberyCreationForm const & src
) : Form(src) { *this = src; }

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) :
	Form("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void	ShrubberyCreationForm::action ( void ) const {
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	ofs(filename.c_str());
	std::string		trees = "            ,@@@@@@@,\n    ,,,.   ,@@@@@@/@@,  .oo8888o.\n ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n`&%\\ ` /%&'    |.|        \\ '|8'\n    |o|        | |         | |\n    |.|        | |         | |\n \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

	ofs << trees;
	ofs.close();
}

ShrubberyCreationForm &		ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const & rhs
)
{
	(void) rhs;
	return *this;
}