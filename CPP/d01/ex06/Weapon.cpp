#include "Weapon.hpp"

Weapon::Weapon( void ) : _type("fist") {
	return;
}

Weapon::Weapon( std::string s ) : _type(s) {
	return;
}

Weapon::~Weapon( void ) {
	return;
}

std::string	const &Weapon::getType( void ) const{
	return this->_type;
}

void		Weapon::setType( std::string s ) {
	this->_type = s;
	return;
}