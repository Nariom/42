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

Fixed::Fixed( int const n ) : _fractionalBits(8) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n * (1 << this->_fractionalBits);
	return;
}

Fixed::Fixed( float const f ) : _fractionalBits(8) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(f * (1 << this->_fractionalBits));
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

float	Fixed::toFloat( void ) const {
	return this->_rawBits / (float) (1 << this->_fractionalBits);
}

int		Fixed::toInt( void ) const {
	return this->_rawBits / (1 << this->_fractionalBits);
}

Fixed &	Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {
	o << rhs.toFloat();
	return o;
}