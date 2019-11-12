#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>

class Bureaucrat;

class Form {

private:

	std::string const	_name;
	std::string const	_target;
	bool				_signed;
	int const			_signGrade;
	int const			_execGrade;

public:

	Form( void );
	Form( Form const & src );
	Form( std::string const name, std::string const target, int sign, int exec );
	~Form( void );

	std::string	getName( void ) const;
	std::string	getTarget( void ) const;
	bool		getSigned( void ) const;
	int			getSignGrade( void ) const;
	int 		getExecGrade( void ) const;

	void			beSigned( Bureaucrat const & bureaucrat );
	void			execute( Bureaucrat const & executor ) const;
	virtual void	action( void ) const = 0;

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

	class FormNotSignedException : public std::exception {
	public:
		FormNotSignedException( void );
		FormNotSignedException( FormNotSignedException const & src );
		~FormNotSignedException( void ) throw();
		FormNotSignedException &	operator=(FormNotSignedException const & rhs);
		virtual const char*	what() const throw();
	};

	Form &	operator=(Form const & rhs);

};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif // FORM_HPP