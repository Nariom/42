# include <iostream>
# include <exception>
# include <cstdlib>
#include "Array.hpp"

int	main( void ) {

	char	* a = new char[10];

	for (int i = 0; i < 10; ++i)
		std::cout << a[i];

	std::cout << std::endl;

	Array<int>	intArray0 = Array<int>();
	std::cout << "intArray0 = Array<int>() : " << intArray0 << std::endl;
	Array<int>	intArray10 = Array<int>(10);
	std::cout << "intArray10 = Array<int>(10) : " << intArray10 << std::endl;
	std::cout << std::endl;

	std::cout << "intArray0[0] : ";
	try {
		std::cout << intArray0[0];
	}
	catch (Array<int>::OutOfBoundException e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Filling intArray10 with rand() % 100 : ";
	for(unsigned int i = 0; i < intArray10.size(); ++i)
		intArray10[i] = rand() % 100;
	std::cout << intArray10 << std::endl;

	std::cout << "intArray10Copy = Array<int>(intArray10) : ";
	Array<int>	intArray10Copy = Array<int>(intArray10);
	std::cout << intArray10Copy << std::endl;

	std::cout << "Filling intArray10 with rand() % 100 : ";
	for(unsigned int i = 0; i < intArray10.size(); ++i)
		intArray10[i] = rand() % 100;
	std::cout << intArray10 << std::endl;

	std::cout << "intArray10Copy : " << intArray10Copy << std::endl;

	std::cout << "intArray10Copy = intArray10 : ";
	intArray10Copy = intArray10;
	std::cout << intArray10 << std::endl;

	std::cout << "Filling intArray10 with rand() % 100 : ";
	for(unsigned int i = 0; i < intArray10.size(); ++i)
		intArray10[i] = rand() % 100;
	std::cout << intArray10 << std::endl;

	std::cout << "intArray10Copy : " << intArray10Copy << std::endl;

	std::cout 	<< "intArray0.size() : " << intArray0.size() << std::endl
				<< "intArray10.size() : " << intArray10.size() << std::endl
				<< "intArray10Copy.size() : " << intArray10Copy.size() << std::endl;

	std::cout << std::endl;

	std::cout << "charArray10 = Array<char>(10) filled with rand() % 26 + 65 : ";
	Array<char>	charArray10 = Array<char>(10);
	for(unsigned int i = 0; i < charArray10.size(); ++i)
		charArray10[i] = rand() % 26 + 65;
	std::cout << charArray10 << std::endl;

	std::cout << std::endl;

	return 1;

}