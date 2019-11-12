#include "Victim.hpp"

Victim::Victim( void ) : _name("Victim") { 
	std::cout << "Some random victim called Victim just popped !";
	std::cout << std::endl;
	return;
}

Victim::Victim( std::string name ) : _name(name) {
	std::cout << "Some random victim called " << this->_name;
	std::cout << " just popped !" << std::endl;
	return;
}

Victim::Victim( Victim const & src ) {
	*this = src;
	std::cout << "Some random victim called " << this->_name;
	std::cout << " just popped !" << std::endl;
	return;
}

Victim::~Victim( void ) {
	std::cout << "Victim " << this->_name;
	std::cout << " just died for no apparent reason !" << std::endl;
	return;
}

std::string		Victim::getName( void ) const {
	return this->_name;
}

void			Victim::getPolymorphed() const {
	std::cout << this->_name << " has been turned into a cute little sheep !";
	std::cout << std::endl;
}

Victim &		Victim::operator=(Victim const & rhs) {
	this->_name = rhs.getName();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Victim const & rhs ) {
	o << "I am " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}