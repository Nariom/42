#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include <iostream>
# include <cstdlib>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

public:

	NinjaTrap( void );
	NinjaTrap( NinjaTrap const & src );
	NinjaTrap( std::string str );
	~NinjaTrap( void );

	unsigned int	meleeAttack( std::string const & target ) const;
	unsigned int	rangedAttack( std::string const & target ) const;
	void			ninjaShoebox(FragTrap & target);
	void			ninjaShoebox(ScavTrap & target);
	void			ninjaShoebox(NinjaTrap & target);

	NinjaTrap &		operator=(NinjaTrap const & rhs);

};

#endif // NINJATRAP_HPP