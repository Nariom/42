#include "Brain.hpp"

Brain::Brain( void ) : _neurons(0) {
	return;
}

Brain::Brain( int n ) : _neurons(n) {
	return;
}

Brain::~Brain( void ) {
	return;
}

int		Brain::getNeurons( void ) const {
	return this->_neurons;
}

void	Brain::setNeurons( int n ) {
	this->_neurons = n;
	return;
}

std::string	Brain::identify( void ) const {
	std::stringstream ss;

	ss << this;
	return ss.str();
}