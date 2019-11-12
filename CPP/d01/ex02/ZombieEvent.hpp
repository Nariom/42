#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include <cstdlib>
#include "Zombie.hpp"


class ZombieEvent {

public:

	ZombieEvent( void );
	~ZombieEvent( void );

	void	setZombieType( int i );
	Zombie	*newZombie( std::string name );
	Zombie	*randomChump( void );

private:

	int		_type;

};

#endif // ZOMBIEEVENT_HPP