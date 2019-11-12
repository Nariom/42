#include <iostream>
#include "Convertor.hpp"

int	main ( int ac, char *av[] ) {
	std::string const	value = av[1];
	Convertor			convert(value);

	if (ac > 1) {
		std::cout << "char: ";
		try {
			char c = convert.charConvert();
			std::cout << c;
		}
		catch (std::bad_cast &bc) {
			std::cout << "impossible";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "usage: convertor <value>" << std::endl;
}