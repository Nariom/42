#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

private:

	ShrubberyCreationForm( void );

	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);

public:

	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	ShrubberyCreationForm( std::string const target );
	~ShrubberyCreationForm( void );

	virtual void	action( void ) const;

};

#endif // SHRUBBERYCREATIONFORM_HPP