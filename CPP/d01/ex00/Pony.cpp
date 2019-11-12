#include "Pony.hpp"
#include <iostream>

Pony::Pony( void ) {
	std::cout << "A pony has born!" << std::endl;
	return;
}

Pony::~Pony( void ) {
	std::cout << "A pony has died..." << std::endl;
	return;
}