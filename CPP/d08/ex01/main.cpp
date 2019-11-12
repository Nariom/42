#include <vector>
#include <iterator>
#include <cstdlib>
#include "span.hpp"

int main()
{
	span	sp = span(5);

	std::cout << std::endl;
	std::cout << "Testing with adding 5, 3, 17, 9, 11 then short/long : " << std::endl;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest : " << sp.shortestSpan() << std::endl;
	std::cout << "longest : " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::vector<int>	myvector;
	span				sp2 = span(6);

	std::cout << std::endl;
	std::cout << "Testing with adding a vector 0, 10, 20, 30, 40, 50 throught iterators : " << std::endl;
	for (int i = 0; i < 60; i += 10)
		myvector.push_back(i);
	sp2.addNumber(myvector.begin(), myvector.end());
	std::cout << "shortest : " << sp2.shortestSpan() << std::endl;
	std::cout << "longest : " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	std::vector<int>	myvector2;
	span				sp3 = span(10000);

	std::cout << std::endl;
	std::cout << "Testing with adding a vector of 10.000 rands throught iterators : " << std::endl;
	for (int i = 0; i < 10000; ++i)
		myvector2.push_back(rand());
	sp3.addNumber(myvector2.begin(), myvector2.end());
	std::cout << "shortest : " << sp3.shortestSpan() << std::endl;
	std::cout << "longest : " << sp3.longestSpan() << std::endl;
	std::cout << std::endl;

	return 1;

}