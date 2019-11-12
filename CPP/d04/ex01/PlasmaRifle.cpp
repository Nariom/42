#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle( void ) : AWeapon("PlasmaRifle", 5, 21) { return; }

PlasmaRifle::PlasmaRifle( PlasmaRifle const & src ) : AWeapon(src) {
	*this = src;
	return;
}

PlasmaRifle::~PlasmaRifle( void ) { return; }

void			PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle &	PlasmaRifle::operator=(PlasmaRifle const & rhs) {
	AWeapon::operator=(rhs);
	return *this;
}