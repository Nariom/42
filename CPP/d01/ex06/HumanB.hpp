#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB {

public:

	HumanB( std::string s );
	~HumanB( void );

	void	attack( void ) const;
	void	setWeapon( Weapon &w );

private:

	std::string	_name;
	Weapon		*_weapon;

};

#endif // HUMANB_HPP