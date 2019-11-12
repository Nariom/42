#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent( void ) : _type(0) {
	return;
}

ZombieEvent::~ZombieEvent( void ) {
	return;
}

void	ZombieEvent::setZombieType( int i ) {
	this->_type = i;
}

Zombie	*ZombieEvent::newZombie( std::string name ) {
	return new Zombie(name, this->_type);
}

Zombie	*ZombieEvent::randomChump( void ) {
	Zombie		*z;
	std::string	name;
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < 6; i++)
		name += alpha[rand() % 26];
	z = new Zombie(name, this->_type);
	z->announce();
	return z;
}