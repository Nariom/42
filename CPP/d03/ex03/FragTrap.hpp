#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <cstdlib>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap( void );
	FragTrap( FragTrap const & src );
	FragTrap( std::string str );
	~FragTrap( void );

	unsigned int	meleeAttack( std::string const & target ) const;
	unsigned int	rangedAttack( std::string const & target ) const;
	unsigned int	vaulthunter_dot_exe( std::string const & target );

	FragTrap &		operator=(FragTrap const & rhs);

};

#endif // FRAGTRAP_HPP