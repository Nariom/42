#include <iostream>
#include <list>
#include <vector>
#include <exception>
#include "easyfind.hpp"

int	main( void ) {

	int							myints[] = {75,23,65,42,13};
	std::list<int>				mylist(myints,myints+5);
	std::list<int>::iterator	lit;
	std::vector<int>			myvector(10);
	std::vector<int>::size_type	sz = myvector.size();
	std::vector<int>::iterator	zit;

  	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	lit = easyfind(mylist, 42);
	if(lit != mylist.end())
		std::cout << *lit << std::endl;
	else
		std::cout << "Not found." << std::endl;

	lit = easyfind(mylist, 21);
	if(lit != mylist.end())
		std::cout << *lit << std::endl;
	else
		std::cout << "Not found." << std::endl;

	zit = easyfind(myvector, 5);
	if(zit != myvector.end())
		std::cout << *zit << std::endl;
	else
		std::cout << "Not found." << std::endl;

	zit = easyfind(myvector, 10);
	if(zit != myvector.end())
		std::cout << *zit << std::endl;
	else
		std::cout << "Not found." << std::endl;

	return 1;

}