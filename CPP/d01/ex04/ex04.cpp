#include <iostream>

int	main( void ) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*ptr = &str;
	std::string &ref = str;

	std::cout << "Using the pointer : " << *ptr << std::endl;
	std::cout << "Using the reference : " << ref << std::endl;
	return 0;
}