#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon {

private:

	std::string	_name;
	int			_apcost;
	int			_damage;

	AWeapon( void );

public:

	AWeapon( AWeapon const & src );
	AWeapon( std::string const & name, int apcost, int damage );
	virtual ~AWeapon( void );

	AWeapon &		operator=(AWeapon const & rhs);

	std::string const	getName() const;
	int					getAPCost() const;
	int					getDamage() const;

	virtual void	attack() const = 0;

};

#endif // AWEAPON_HPP
