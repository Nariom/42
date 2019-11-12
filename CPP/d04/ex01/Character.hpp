#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {

private:

	std::string	_name;
	int			_ap;
	AWeapon *	_weapon;

	Character( void );

public:

	Character( Character const & src );
	Character( std::string const & name );
	~Character( void );

	Character &			operator=(Character const & rhs);

	std::string const	getName() const;
	int					getAp() const;
	AWeapon *			getWeapon() const;

	void				recoverAP();
	void				equip( AWeapon* weapon );
	void				attack( Enemy* enemy );

};

std::ostream &	operator<<( std::ostream & o, Character const & rhs );

#endif // CHARACTER_HPP