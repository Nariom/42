#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA {

public:

	HumanA( std::string s, Weapon &w );
	~HumanA( void );

	void	attack( void ) const;

private:

	std::string	_name;
	Weapon		&_weapon;

};

#endif // HUMANA_HPP