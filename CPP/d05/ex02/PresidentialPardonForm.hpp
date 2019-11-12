#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class PresidentialPardonForm : public Form {

private:

	PresidentialPardonForm( void );

	PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);

public:

	PresidentialPardonForm( PresidentialPardonForm const & src );
	PresidentialPardonForm( std::string const target );
	~PresidentialPardonForm( void );

	virtual void	action( void ) const;

};

#endif // PRESIDENTIALPARDONFORM_HPP