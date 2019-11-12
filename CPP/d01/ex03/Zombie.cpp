#include "Zombie.hpp"

Zombie::Zombie( void ) : _name(""), _type(0) {
	std::cout << "A zombie has raised!" << std::endl;
	return;
}

Zombie::Zombie( std::string s, int i ) : _name(s), _type(i) {
	std::cout << "A zombie has raised!" << std::endl;
	return;
}

Zombie::~Zombie( void ) {
	std::cout << "A zombie has fallen!" << std::endl;
	return;
}

std::string	Zombie::getName( void ) const {
	return this->_name;
}

int			Zombie::getType( void ) const {
	return this->_type;
}

void		Zombie::setName( std::string s ) {
	this->_name = s;
	return;
}

void		Zombie::setType( int i ) {
	this->_type = i;
	return;
}

void		Zombie::announce( void ) const {
	std::cout << "<" << this->getName() << " (" << this->getType();
	std::cout  << ")> Braiiiiiiinnnssss..." << std::endl;
}