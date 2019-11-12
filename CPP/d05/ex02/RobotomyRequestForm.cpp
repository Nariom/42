#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form() {}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm const & src
) : Form(src) { *this = src; }

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) :
	Form("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void	RobotomyRequestForm::action ( void ) const {
	std::cout << "Fffrrrzzzzzziiiiiiiiiiiikkkrkrrr wzzz wzzzzzz" << std::endl;
	if (rand() % 2 == 0)
		std::cout	<< this->getTarget()
					<< " has been robotomized successfully." << std::endl;
	else
		std::cout << "The operation is a failure." << std::endl;
}

RobotomyRequestForm &		RobotomyRequestForm::operator=(
	RobotomyRequestForm const & rhs
)
{
	(void) rhs;
	return *this;
}