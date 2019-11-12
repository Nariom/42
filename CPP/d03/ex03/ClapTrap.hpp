#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {

public:

	ClapTrap( void );
	ClapTrap( ClapTrap const & src );
	ClapTrap( std::string str );
	~ClapTrap( void );

	ClapTrap &	operator=(ClapTrap const & rhs);

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

protected:

	unsigned int		_hp;
	unsigned int		_maxHp;
	unsigned int		_ep;
	unsigned int		_maxEp;
	unsigned int		_level;
	std::string			_name;
	unsigned int		_mDmg;
	unsigned int		_rDmg;
	unsigned int		_dmgReduct;

	unsigned int	_melee( std::string const & target ) const;
	unsigned int	_ranged( std::string const & target ) const;

};

#endif // CLAPTRAP_HPP