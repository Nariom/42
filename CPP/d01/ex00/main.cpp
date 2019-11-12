#include "Pony.hpp"
#include <iostream>

void	ponyOnTheHeap( void ) {
	Pony	*p = new Pony;
	delete p;
	return;
}

void	ponyOnTheStack( void ) {
	Pony	p;
	return;
}

int		main( void ) {
	std::cout << "Let's make a pony on the heap." << std::endl;
	ponyOnTheHeap();
	std::cout << "Let's make a pony on the stack." << std::endl;
	ponyOnTheStack();
	std::cout << "Done. Happy ? ;D" << std::endl;
	return 0;
}