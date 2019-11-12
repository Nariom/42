#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int N, int T ) : _type(T), _size(N) {
	this->_crowd = new Zombie[N];
	std::string	name;
	std::string alpha = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++)
			name += alpha[rand() % 26];
		this->_crowd[i].setName(name);
		this->_crowd[i].setType(T);
		name.clear();
	}
	return;
}

ZombieHorde::~ZombieHorde( void ) {
	delete [] this->_crowd;
	return;
}

void	ZombieHorde::announce( void ) const {
	for (int i = 0; i < this->_size; i++)
		this->_crowd[i].announce();
}