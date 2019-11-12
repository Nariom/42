#include "SuperMutant.hpp"

SuperMutant::SuperMutant( void ) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant( SuperMutant const & src ) : Enemy(src) {
	*this = src;
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::~SuperMutant( void ) {
	std::cout << "Aaargh ..." << std::endl;
	return;
}

void			SuperMutant::takeDamage(int dmg) {
	Enemy::takeDamage(dmg - 3);
}

SuperMutant &	SuperMutant::operator=(SuperMutant const & rhs) {
	Enemy::operator=(rhs);
	return *this;
}