#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) { *this = src; }

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat( void ) {}

std::string	Bureaucrat::getName( void ) const { return this->_name; }

int			Bureaucrat::getGrade( void ) const { return this->_grade; }

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & rhs) {
	(void) rhs;
	return *this;
}

Bureaucrat &	Bureaucrat::operator++( void ) {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
	return *this;
}

Bureaucrat &	Bureaucrat::operator--( void ) {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs ) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(
	GradeTooHighException const & src
) { *this = src; }

Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Bureaucrat::GradeTooHighException &	Bureaucrat::GradeTooHighException::operator=(
	Bureaucrat::GradeTooHighException const & rhs
) { (void) rhs; return *this; }

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{ return "Grade too high."; }

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(
	GradeTooLowException const & src
) { *this = src; }

Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Bureaucrat::GradeTooLowException &	Bureaucrat::GradeTooLowException::operator=(
	Bureaucrat::GradeTooLowException const & rhs
) { (void) rhs; return *this; }

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{ return "Grade too low."; }