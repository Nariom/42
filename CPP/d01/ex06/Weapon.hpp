#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon {

public:

	Weapon( void );
	Weapon( std::string s );
	~Weapon( void );

	std::string	const &getType( void ) const;
	void		setType( std::string s );

private:

	std::string	_type;

};

#endif // WEAPON_HPP