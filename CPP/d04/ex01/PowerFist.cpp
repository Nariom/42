#include "PowerFist.hpp"

PowerFist::PowerFist( void ) : AWeapon("PowerFist", 8, 50) { return; }

PowerFist::PowerFist( PowerFist const & src ) : AWeapon(src) {
	*this = src;
	return;
}

PowerFist::~PowerFist( void ) { return; }

void			PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist &	PowerFist::operator=(PowerFist const & rhs) {
	AWeapon::operator=(rhs);
	return *this;
}