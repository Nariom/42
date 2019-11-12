#include "HumanA.hpp"

HumanA::HumanA( std::string s, Weapon &w ) : _name(s), _weapon(w) {
	return;
}

HumanA::~HumanA( void ) {
	return;
}

void	HumanA::attack( void ) const {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	return;
}