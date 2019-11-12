#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate( void ) {

	Base *	ret;
	int		nb = rand() % 3;

	switch (nb) {
		case 0:
			std::cout << "[ Making A ]" << std::endl;
			ret = new A;
			break;
		case 1:
			std::cout << "[ Making B ]" << std::endl;
			ret = new B;
			break;
		case 2:
			std::cout << "[ Making C ]" << std::endl;
			ret = new C;
			break;
		default:
			ret = 0;
			break;
	}

	return ret;

}

void	identify_from_pointer( Base * p ) {

	A *	p1 = dynamic_cast<A *>(p);
	B *	p2 = dynamic_cast<B *>(p);
	C *	p3 = dynamic_cast<C *>(p);

	if (p1)
		std::cout << "It's an A!" << std::endl;
	else if (p2)
		std::cout << "It's a B!" << std::endl;
	else if (p3)
		std::cout << "It's a C!" << std::endl;
	else
		std::cout << "WTF not A not B not C what did you do?!!" << std::endl;

}

int		main( void ) {

	Base *	obj;

	for(int i = 0; i < 9; ++i)
	{
		obj = generate();
		identify_from_pointer(obj);
		delete obj;
	}

	return 1;

}