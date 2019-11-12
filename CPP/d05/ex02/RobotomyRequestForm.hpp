#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

private:

	RobotomyRequestForm( void );

	RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);

public:

	RobotomyRequestForm( RobotomyRequestForm const & src );
	RobotomyRequestForm( std::string const target );
	~RobotomyRequestForm( void );

	virtual void	action( void ) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP