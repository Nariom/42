#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <cstdlib>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap( void );
	ScavTrap( ScavTrap const & src );
	ScavTrap( std::string str );
	~ScavTrap( void );

	unsigned int	meleeAttack( std::string const & target ) const;
	unsigned int	rangedAttack( std::string const & target ) const;
	void			challengeNewcomer( std::string const & target ) const;

	ScavTrap &		operator=(ScavTrap const & rhs);

};

#endif // SCAVTRAP_HPP