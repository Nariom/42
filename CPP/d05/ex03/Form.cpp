#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) :
	_name("form"),
	_target("target"),
	_signed(false),
	_signGrade(150),
	_execGrade(150)
{}

Form::Form( Form const & src ) :
	_name("form"),
	_target("target"),
	_signed(false),
	_signGrade(150),
	_execGrade(150)
{ *this = src; }

Form::Form(
	std::string const name,
	std::string const target,
	int sign,
	int exec
) :
	_name(name),
	_target(target),
	_signed(false),
	_signGrade(sign),
	_execGrade(exec)
{
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
}

Form::~Form( void ) {}

std::string	Form::getName( void ) const { return this->_name; }

std::string	Form::getTarget( void ) const { return this->_target; }

bool		Form::getSigned( void ) const { return this->_signed; }

int 		Form::getSignGrade( void ) const { return this->_signGrade; }

int 		Form::getExecGrade( void ) const { return this->_execGrade; }

void		Form::beSigned( Bureaucrat const & bureaucrat ) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

void		Form::execute( Bureaucrat const & executor ) const {
	if (!this->_signed)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->_execGrade)
		throw Form::GradeTooLowException();
	else
		this->action();
}

Form &			Form::operator=(Form const & rhs) {
	(void) rhs;
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Form const & rhs ) {
	o	<< rhs.getName() << ", Form grade " << rhs.getSignGrade()
		<< " [sign] " << rhs.getExecGrade() << " [execute] (";
	if (!rhs.getSigned())
		o << "not ";
	o << "signed)";
	return o;
}

Form::GradeTooHighException::GradeTooHighException( void ) {}

Form::GradeTooHighException::GradeTooHighException(
	GradeTooHighException const & src
) { *this = src; }

Form::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Form::GradeTooHighException &	Form::GradeTooHighException::operator=(
	Form::GradeTooHighException const & rhs
) { (void) rhs; return *this; }

const char*	Form::GradeTooHighException::what() const throw()
{ return "Grade too high."; }

Form::GradeTooLowException::GradeTooLowException( void ) {}

Form::GradeTooLowException::GradeTooLowException(
	GradeTooLowException const & src
) { *this = src; }

Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Form::GradeTooLowException &	Form::GradeTooLowException::operator=(
	Form::GradeTooLowException const & rhs
) { (void) rhs; return *this; }

const char*	Form::GradeTooLowException::what() const throw()
{ return "Grade too low."; }

Form::FormNotSignedException::FormNotSignedException( void ) {}

Form::FormNotSignedException::FormNotSignedException(
	FormNotSignedException const & src
) { *this = src; }

Form::FormNotSignedException::~FormNotSignedException( void ) throw() {}

Form::FormNotSignedException &	Form::FormNotSignedException::operator=(
	Form::FormNotSignedException const & rhs
) { (void) rhs; return *this; }

const char*	Form::FormNotSignedException::what() const throw()
{ return "Form not signed."; }