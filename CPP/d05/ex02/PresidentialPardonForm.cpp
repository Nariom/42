#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form() {}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const & src
) : Form(src) { *this = src; }

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) :
	Form("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void	PresidentialPardonForm::action ( void ) const {
	std::cout	<< this->getTarget() << " has been pardoned by Zafod Beeblebrox."
				<< std::endl;
}

PresidentialPardonForm &		PresidentialPardonForm::operator=(
	PresidentialPardonForm const & rhs
)
{
	(void) rhs;
	return *this;
}