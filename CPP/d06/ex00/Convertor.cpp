#include "Convertor.hpp"

Convertor::Convertor( void ) : _value("") {}

Convertor::Convertor( Convertor const & src ) { *this = src; }

Convertor::Convertor( std::string value ) : _value(value) {}

Convertor::~Convertor( void ) {}

std::string const	Convertor::getValue( void ) const { return this->_value; }

char				Convertor::charConvert() {
	char		c = 0;
	try {
		c = reinterpret_cast<char>(this->_value);
	}
	catch (std::bad_cast &bc) {
		throw bc;
	}
	return c;
}

/*operator			Convertor::int() {

}

operator			Convertor::float() {

}

operator			Convertor::double() {

}*/

Convertor &		Convertor::operator=(Convertor const & rhs) { (void) rhs; return *this; }

std::ostream &	operator<<( std::ostream & o, Convertor const & rhs ) {
	o << rhs.getValue();
	return o;
}