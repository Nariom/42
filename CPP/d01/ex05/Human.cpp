#include "Human.hpp"

Human::Human( void ) : _brain(Brain()) {
	return;
}

Human::~Human( void ) {
	return;
}

std::string	Human::identify( void ) const {
	return this->_brain.identify();
}

Brain	const Human::getBrain( void ) const {
	return this->_brain;
}