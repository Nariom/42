#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>


class Zombie {

public:

	Zombie( void );
	Zombie( std::string s, int i );
	~Zombie( void );

	std::string	getName( void ) const;
	int			getType( void ) const;
	void		setName( std::string s );
	void		setType( int i );
	void		announce( void ) const;

private:

	std::string	_name;
	int			_type;

};

#endif // ZOMBIE_HPP