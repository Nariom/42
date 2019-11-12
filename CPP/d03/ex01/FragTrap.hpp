#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <cstdlib>

class FragTrap {

public:

	FragTrap( void );
	FragTrap( FragTrap const & src );
	FragTrap( std::string str );
	~FragTrap( void );

	FragTrap &	operator=(FragTrap const & rhs);

	unsigned int	getHp( void ) const;
	void			setHp( unsigned int val );
	unsigned int	getMaxHp( void ) const;
	void			setMaxHp( unsigned int val );
	unsigned int	getEp( void ) const;
	void			setEp( unsigned int val );
	unsigned int	getMaxEp( void ) const;
	void			setMaxEp( unsigned int val );
	unsigned int	getLevel( void ) const;
	void			setLevel( unsigned int val );
	std::string 	getName( void ) const;
	void			setName( std::string val );
	unsigned int	getMDmg( void ) const;
	void			setMDmg( unsigned int val );
	unsigned int	getRDmg( void ) const;
	void			setRDmg( unsigned int val );
	unsigned int	getDmgReduct( void ) const;
	void			setDmgReduct( unsigned int val );

	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amnount );
	unsigned int	meleeAttack( std::string const & target ) const;
	unsigned int	rangedAttack( std::string const & target ) const;
	unsigned int	vaulthunter_dot_exe( std::string const & target );

private:

	unsigned int	_hp;
	unsigned int	_maxHp;
	unsigned int	_ep;
	unsigned int	_maxEp;
	unsigned int	_level;
	std::string		_name;
	unsigned int	_mDmg;
	unsigned int	_rDmg;
	unsigned int	_dmgReduct;

};

#endif // FRAGTRAP_HPP