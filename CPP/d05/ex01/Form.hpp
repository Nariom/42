#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>

class Bureaucrat;

class Form {

private:

	std::string const	_name;
	bool				_signed;
	int const			_signGrade;
	int const			_execGrade;

	Form( void );

	Form &	operator=(Form const & rhs);

public:

	Form( Form const & src );
	Form( std::string const name, int sign, int exec );
	~Form( void );

	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getSignGrade( void ) const;
	int 		getExecGrade( void ) const;

	void		beSigned( Bureaucrat const & bureaucrat );

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException( void );
		GradeTooHighException( GradeTooHighException const & src );
		~GradeTooHighException( void ) throw();
		GradeTooHighException &	operator=(GradeTooHighException const & rhs);
		virtual const char*		what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException( void );
		GradeTooLowException( GradeTooLowException const & src );
		~GradeTooLowException( void ) throw();
		GradeTooLowException &	operator=(GradeTooLowException const & rhs);
		virtual const char*	what() const throw();
	};

};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif // FORM_HPP