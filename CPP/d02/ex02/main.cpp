#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;
	Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << "a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "--c : " << --c << std::endl;
	std::cout << "c-- : " << c-- << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "d : " << d << std::endl;
	std::cout << "a <= c : " << ((a <= c)?"true":"false") << std::endl;
	std::cout << "min(a,c) : " << Fixed::min( a, c ) << std::endl;
	std::cout << "b <= d : " << ((b <= d)?"true":"false") << std::endl;
	std::cout << "min(b,d) : " << Fixed::min( b, d ) << std::endl;
	std::cout << "a >= c : " << ((a >= c)?"true":"false") << std::endl;
	std::cout << "max(a,c) : " << Fixed::max( a, c ) << std::endl;
	std::cout << "b >= d : " << ((b >= d)?"true":"false") << std::endl;
	std::cout << "max(b,d) : " << Fixed::max( b, d ) << std::endl;
	std::cout << "a + c : " << a + c << std::endl;
	std::cout << "b - d : " << b - d << std::endl;

	return 0;

}