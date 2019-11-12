#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int	main( void )
{
	std::cout << "*--- creating Sorcerer on the stack ---*" << std::endl;
	Sorcerer	robert("Robert", "the Magnificent");
	std::cout << "*--- creating Victim on the stack ---*" << std::endl;
	Victim		jim("Jimmy");
	std::cout << "*--- creating Peon on the stack ---*" << std::endl;
	Peon		joe("Joe");
	std::cout << "*--- creating Victim on the stack with operator= Peon ---*" << std::endl;
	Victim		joe2 = joe;
	std::cout << "*--- creating Peon on the heap as Victim* ---*" << std::endl;
	Victim *	john = new Peon("john");

	std::cout << "*--- using operator<< with all ---*" << std::endl;
	std::cout << robert << jim << joe << joe2 << *john;
	std::cout << "*--- polymorph Victim ---*" << std::endl;
	robert.polymorph(jim);
	std::cout << "*--- polymorph Peon ---*" << std::endl;
	robert.polymorph(joe);
	std::cout << "*--- polymorph Victim = ---*" << std::endl;
	robert.polymorph(joe2);
	std::cout << "*--- polymorph Victim* Peon ---*" << std::endl;
	robert.polymorph(*john);

	std::cout << "*--- deleting Victim* Peon ---*" << std::endl;
	delete john;

	std::cout << "*--- autodestructions when program ends ---*" << std::endl;

	return 0;
}