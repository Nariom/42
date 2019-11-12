#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0), _fractionalBits(8) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src ) : _fractionalBits(8) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return;
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}