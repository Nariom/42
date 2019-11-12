#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0), _fractionalBits(8) {
	return;
}

Fixed::Fixed( Fixed const & src ) : _fractionalBits(8) {
	*this = src;
	return;
}

Fixed::Fixed( int const n ) : _fractionalBits(8) {
	this->_rawBits = n * (1 << this->_fractionalBits);
	return;
}

Fixed::Fixed( float const f ) : _fractionalBits(8) {
	this->_rawBits = roundf(f * (1 << this->_fractionalBits));
	return;
}

Fixed::~Fixed( void ) {
	return;
}

int		Fixed::getRawBits( void ) const {;
	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw ) {
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
	this->_rawBits = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & rhs) const {
	return this->_rawBits > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const & rhs) const {
	return this->_rawBits < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	return this->_rawBits >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	return this->_rawBits <= rhs.getRawBits();
}
bool	Fixed::operator==(Fixed const & rhs) const {
	return this->_rawBits == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	return !(*this == rhs);
}

Fixed	Fixed::operator+(Fixed const & rhs) const {
	Fixed	ret;
	ret.setRawBits(this->_rawBits + rhs.getRawBits());
	return ret;
}

Fixed	Fixed::operator-(Fixed const & rhs) const {
	Fixed	ret;
	ret.setRawBits(this->_rawBits - rhs.getRawBits());
	return ret;
}

Fixed	Fixed::operator*(Fixed const & rhs) const {
	Fixed	ret;
	ret.setRawBits(this->_rawBits * rhs.getRawBits() / (1 << this->_fractionalBits));
	return ret;
}

Fixed	Fixed::operator/(Fixed const & rhs) const {
	Fixed	ret(this->toFloat() / rhs.toFloat());
	return ret;
}

Fixed &	Fixed::operator++( void ) {
	this->_rawBits += 1;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed ret(*this);
	this->_rawBits += 1;
	return ret;
}

Fixed &	Fixed::operator--( void ) {
	this->_rawBits -= 1;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed ret(*this);
	this->_rawBits -= 1;
	return ret;
}

Fixed &			Fixed::min(Fixed & a, Fixed & b) {
	return !( b < a ) ? a : b;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b) {
	return !( b < a ) ? a : b;
}

Fixed &			Fixed::max(Fixed & a, Fixed & b) {
	return ( a < b ) ? b : a;
}
Fixed const &	Fixed::max(Fixed const & a, Fixed const & b) {
	return ( a < b ) ? b : a;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) {
	o << rhs.toFloat();
	return o;
}