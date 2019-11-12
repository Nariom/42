#include "Peon.hpp"

Peon::Peon( void ) : Victim() { 
	this->_name = "Peon";
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon( std::string name ) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon( Peon const & src ) : Victim (src) {
	*this = src;
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon( void ) {
	std::cout << "Bleuark..." << std::endl;
	return;
}

void			Peon::getPolymorphed() const {
	std::cout << this->_name << " has been turned into a pink pony !";
	std::cout << std::endl;
}

Peon &			Peon::operator=(Peon const & rhs) {
	Victim::operator=(rhs);
	return *this;
}