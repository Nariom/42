#include "ZombieEvent.hpp"

int	main( void ) {
	ZombieEvent	ze;
	Zombie		*z;

	z = ze.newZombie("Blrblrblrblrblr");
	z->announce();
	delete z;
	ze.setZombieType(1);
	z = ze.newZombie("JoJo");
	z->announce();
	delete z;
	ze.setZombieType(42);
	for (int i = 0; i < 5; i++) {
		z = ze.randomChump();
		delete z;
	}
	return 0;
}