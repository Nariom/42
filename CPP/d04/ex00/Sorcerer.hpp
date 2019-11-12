#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include "Victim.hpp"

class Sorcerer {

public:

	Sorcerer( Sorcerer const & src );
	Sorcerer( std::string name, std::string title );
	~Sorcerer( void );

	Sorcerer &	operator=(Sorcerer const & rhs);

	std::string	getName( void ) const;
	std::string	getTitle( void ) const;

	void		polymorph(Victim const & victim) const;

private:

	std::string	_name;
	std::string	_title;

	Sorcerer( void );

};

std::ostream &	operator<<( std::ostream & o, Sorcerer const & rhs );

#endif // SORCERER_HPP