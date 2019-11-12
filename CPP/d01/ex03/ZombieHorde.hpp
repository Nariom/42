#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include <cstdlib>
#include "Zombie.hpp"


class ZombieHorde {

public:

	ZombieHorde( int N, int T );
	~ZombieHorde( void );

	void	announce( void ) const;

private:

	int		_type;
	int		_size;
	Zombie	*_crowd;

};

#endif // ZOMBIEHORDE_HPP