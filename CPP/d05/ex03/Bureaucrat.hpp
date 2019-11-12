#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class Form;

class Bureaucrat {

private:

	std::string const	_name;
	int					_grade;

	Bureaucrat( void );

	Bureaucrat &	operator=(Bureaucrat const & rhs);

public:

	Bureaucrat( Bureaucrat const & src );
	Bureaucrat( std::string const name, int grade );
	~Bureaucrat( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;

	void		signForm(Form & form) const;
	void		executeForm(Form const & form) const;

	Bureaucrat &	operator++( void );
	Bureaucrat &	operator--( void );

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

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif // BUREAUCRAT_HPP