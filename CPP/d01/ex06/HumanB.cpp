#include "HumanB.hpp"

HumanB::HumanB( std::string s ) : _name(s) {
	return;
}

HumanB::~HumanB( void ) {
	return;
}

void	HumanB::attack( void ) const {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	return;
}

void	HumanB::setWeapon( Weapon &w ) {
	this->_weapon = &w;
}