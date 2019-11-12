#include "RadScorpion.hpp"

RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::RadScorpion( RadScorpion const & src ) : Enemy(src) {
	*this = src;
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion( void ) {
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

RadScorpion &	RadScorpion::operator=(RadScorpion const & rhs) {
	Enemy::operator=(rhs);
	return *this;
}